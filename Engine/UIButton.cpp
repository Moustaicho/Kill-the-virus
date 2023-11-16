#include "UIButton.h"

UIButton::UIButton() : GameObject("UIButton")
	, text("Button")
	, textSize(10)
	, margin({10,10})
	, box({ 0, 0, 150, 50 })
	, colorText(BLACK)
	, colorBase(WHITE)
	, colorClick(DARKGRAY)
	, colorHover(LIGHTGRAY)
	, currentButtonColor(colorBase)
	, mouseHover(false)
	
{
}

void UIButton::Start()
{
	
}

void UIButton::Update()
{
	if (CheckCollisionPointRec(GetMousePosition(), box))
	{
		if(IsMouseButtonDown(0))
		{
			currentButtonColor = colorClick;
		}
		else if (IsMouseButtonReleased(0))
		{
			if (actionFunction != nullptr)
			{
				actionFunction();
			}
		}
		else
		{
			currentButtonColor = colorHover;
		}
	}
	else 
	{ 
		currentButtonColor = colorBase;
	}
}

void UIButton::Draw()
{
	box.x = GetPosition().x;
	box.y = GetPosition().y;
	DrawRectangleRec(box, currentButtonColor);
	DrawText(text.c_str(), box.x + margin.x, box.y + margin.y, textSize, colorText);
}

void UIButton::End()
{

}

void UIButton::SetText(std::string text)
{
	this->text = text;
}

void UIButton::SetTextSize(int size)
{
	textSize = size;
}

void UIButton::SetSize(int width, int height)
{
	box.width = width;
	box.height = height;
}

void UIButton::SetMargin(int x, int y)
{
	margin = { x, y };
}

Rectangle UIButton::GetButtonBox()
{
	return box;
}

void UIButton::CenterText()
{
	int textWidth = MeasureText(text.c_str(), textSize);
	margin.x = (box.width - textWidth) /2;
}

void UIButton::SetBaseColor(Color color)
{
	colorBase = color;
}
void UIButton::SetClickColor(Color color)
{
	colorClick = color;
}
void UIButton::SetHoverColor(Color color)
{
	colorHover = color;
}