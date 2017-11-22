#pragma once
#include <Windows.h>
#include <string>
class WinPipe
{
public:
	WinPipe();
	~WinPipe();
	bool create_pipe(LPCWSTR pipe_name);
	bool close();
	bool connect();
	bool send(std::string msg);
private:
	HANDLE pipe = nullptr;
};

