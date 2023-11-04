#pragma once
#include "raylib.h"

class Window
{
private:
	Vector2i position;
	Vector2i size;
public:
	Window(int width, int height, const char* title);

	void SetPosition(int x, int y);
	void SetSize(int width, int height);

	Vector2i GetSize();
};

