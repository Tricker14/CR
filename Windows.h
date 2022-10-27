#pragma once
#include <Windows.h>

class Windows
{
public:
	static void SetWindowSize(int width, int height);

	static void SetScreenBufferSize(int width, int height);

	static void DisableResizeWindow();


	static void setconsolecolor(int textColor, int bgColor);

	static void GotoXY(int x, int y);

	static void ShowConsoleCursor(bool showFlag);

};