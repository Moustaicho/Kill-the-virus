#pragma once
#include "GameObject.h"
class UIButton : public GameObject
{
private:
	std::string text;
	int textSize;
	Vector2i margin;

	Color colorText;

	Color currentButtonColor;
	Color colorBase;
	Color colorClick;
	Color colorHover;

	Rectangle box;

	bool mouseHover;
public:
	UIButton();

	void (*actionFunction)();

	void Start();
	void Update();
	void Draw();
	void End();

	void SetText(std::string text);
	void SetTextSize(int size);
	void SetSize(int width, int height);
	void SetMargin(int x, int y);
	Rectangle GetButtonBox();

	void CenterText();
};

