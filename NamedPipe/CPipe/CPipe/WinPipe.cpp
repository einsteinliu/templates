#include "WinPipe.h"

WinPipe::WinPipe()
{
}


WinPipe::~WinPipe()
{
}

bool WinPipe::create_pipe(LPCWSTR pipe_name)
{
	// Create a pipe to send data
	pipe = CreateNamedPipe(
		pipe_name, // name of the pipe
		PIPE_ACCESS_DUPLEX, // 1-way pipe -- send only
		PIPE_TYPE_BYTE, // send data as a byte stream
		5, // allow 5 instance of this pipe
		0, // no outbound buffer
		0, // no inbound buffer
		30, // use default wait time
		NULL // use default security attributes
	);
	if (pipe == NULL || pipe == INVALID_HANDLE_VALUE)
		return false;
	else
		return true;
}

bool WinPipe::close()
{
	return (CloseHandle(pipe) == TRUE);
}

bool WinPipe::connect()
{
	// This call blocks until a client process connects to the pipe
	BOOL result = ConnectNamedPipe(pipe, NULL);
	if (!result) {
		CloseHandle(pipe); // close the pipe		
		return false;
	}
	else
		return true;
}

bool WinPipe::send(std::string msg)
{	
	std::wstring widestr = std::wstring(msg.begin(), msg.end());

	// This call blocks until a client process reads all the data	
	DWORD numBytesWritten = 0;
	BOOL result = WriteFile(
		pipe, // handle to our outbound pipe
		widestr.c_str(), // data to send
		msg.length() * sizeof(wchar_t), // length of data to send (bytes)
		&numBytesWritten, // will store actual amount of data sent
		NULL // not using overlapped IO
	);

	if (result) 
		return true;
	else
		return false;
}
