import win32file
import win32pipe
import ctypes
import io
import sys
import struct
import time

hk32 = ctypes.windll.LoadLibrary('kernel32.dll')

if sys.maxsize > 2**32:
    def ctypes_handle(handle):
        return ctypes.c_ulonglong(handle)
else:
    def ctypes_handle(handle):
        return ctypes.c_uint(handle)

GENERIC_READ = 0x80000000
GENERIC_WRITE = 0x40000000
GENERIC_EXECUTE = 0x20000000
GENERIC_ALL = 0x10000000
FILE_SHARE_READ = 0x00000001
FILE_SHARE_WRITE = 0x00000002
OPEN_EXISTING = 0x00000003
FILE_ATTRIBUTE_NORMAL = 0x00000080

class PyPipeReader:

        def __init__(self,pipe_addr):

                self.name = pipe_addr
                self.connected = False

        def wait_for_messge(self,timeout):

                if self.connect(timeout):
                        return self.read()
                else:
                        return ""

        def connect(self, timeout):

                scan_interval = 0.05
                if timeout is not -1:
                        scan_max = timeout/scan_interval
                else:
                        scan_max = -1
                while True:
                        self.handle = hk32['CreateFileA'](
                                ctypes.c_char_p(bytes(self.name, 'utf8')),
                                ctypes.c_uint(GENERIC_READ | GENERIC_WRITE),
                                ctypes.c_uint(FILE_SHARE_READ|FILE_SHARE_WRITE),
                                0,  # default security
                                ctypes.c_uint(OPEN_EXISTING),
                                FILE_ATTRIBUTE_NORMAL,
                                0  # no template file
                        )
                        if(self.handle is not -1):
                                self.connected = True
                                break
                        else:
                                if scan_max is not -1:
                                        scan_max = scan_max - 1
                                        if scan_max < 0:
                                                print("Time out .. \n")
                                                break
                                time.sleep(0.05)

                return self.connected

        def  read(self):

                if not self.connected:
                        return ""

                byte_buf = ctypes.create_string_buffer(4096)
                byte_count = b'\x00\x00\x00\x00'
                ret = hk32['ReadFile'](
                        ctypes_handle(self.handle),
                        byte_buf,
                        4096,
                        ctypes.c_char_p(byte_count),
                        0
                )

                byte_count = struct.unpack('I',byte_count)[0]
                rawmsg = byte_buf[0:byte_count]
                return rawmsg.decode("utf-8")