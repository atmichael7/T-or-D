#include <iostream>
#include <windows.h>

#ifndef PRINTLETTER_H
#define PRINTLETTER_H

using namespace std;

void PLR(string message, int rate)
{
	for (int i = 0; i < message.size(); i++)
	{
		cout << message[i];
		Sleep(rate);
	}
	cout << endl;
}


#endif
