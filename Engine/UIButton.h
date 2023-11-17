#pragma once
#include "GameObject.h"
#include "FontLibrary.h"
class UIButton : public GameObject
{
private:
	std::string text;
	int textSize;
	Vector2i margin;

	Color currentTextColor;
	Color colorTextBase;
	Color colorTextClick;
	Color colorTextHover;

	Color currentButtonColor;
	Color colorBase;
	Color colorClick;
	Color colorHover;

	Rectangle box;

	Font textFont;

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

	void SetBaseColor(Color color);
	void SetClickColor(Color color);
	void SetHoverColor(Color color);

	void SetTextBaseColor(Color color);
	void SetTextClickColor(Color color);
	void SetTextHoverColor(Color color);

	void SetFont(Font font);
};

