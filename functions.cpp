#ifndef FUNCTIONS
#define FUNCTIONS

#include <Windows.h>

void no_cursor()
{
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursor;

	GetConsoleCursorInfo(handle, &cursor);

	cursor.bVisible = false;

	SetConsoleCursorInfo(handle, &cursor);
}



#endif