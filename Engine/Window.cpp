#include "Window.h"
#include <iostream>

Window::Window(int width, int height, const char* title)
{
	SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
	size = { width, height };
	InitWindow(width, height, title);
	SetWindowPosition(100, 100);
	position = { 100, 100 };
}

void Window::SetPosition(int x, int y)
{
	position = { x, y };
	SetWindowPosition(x, y);
}

Vector2i Window::GetPosition()
{
	return position;
}

void Window::SetSize(int width, int height)
{
	size = { width, height };
	SetWindowSize(width, height);
}

Vector2i Window::GetSize()
{
	return size;
}