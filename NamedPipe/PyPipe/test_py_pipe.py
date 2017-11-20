import win32file
import win32pipe
import ctypes
import io
import sys
import struct
import PyPipe

my_pipe = PyPipe.PyPipeReader(r'\\.\pipe\my_pipe')
while True:
        print(my_pipe.wait_for_messge(-1))