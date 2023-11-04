#include "Window.h"

Window::Window(int width, int height, const char* title)
{
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

void Window::SetSize(int width, int height)
{
	size = { width, height };
	SetWindowSize(width, height);
}

Vector2i Window::GetSize()
{
	return size;
}