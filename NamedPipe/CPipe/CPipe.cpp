#include <iostream>
#include "CPipe\WinPipe.h"

using namespace std;

int main()
{
	WinPipe win_pipe;
	int i = 0;
	while(win_pipe.create_pipe(L"\\\\.\\pipe\\my_pipe") && win_pipe.connect())
	{
		win_pipe.send(to_string(i));						
		win_pipe.close();
		i++;
		system("pause");
	}
}