// Created by Michael Barrett (CSUSB)

// This will print out letter by letter of what the caller types
// (EX): PLR("Hello world!", 500);
//            ^ Message ^     ^ Rate it will be typed out in milliseconds(ms)
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
