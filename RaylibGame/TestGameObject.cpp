#include "TestGameObject.h"
#include <iostream>
TestGameObject::TestGameObject() : GameObject("TestGameObject")
{
}
void TestGameObject::Start()
{
	std::cout << "Child" << std::endl;
	std::cout << std::to_string(GetPosition().x) << " " << std::to_string(GetPosition().y) << std::endl;
}

void TestGameObject::Update()
{
	Vector2 newPos = GetPosition() + Vector2{1.0f, 0.0f};
	this->SetPosition(newPos);
	std::cout << std::to_string(newPos.x) << " " << std::to_string(newPos.y) << std::endl;
}

void TestGameObject::Draw()
{
	DrawText("Child", GetPosition().x, GetPosition().y, 40, RED);
}
