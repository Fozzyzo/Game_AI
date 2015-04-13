#include "InputInfo.h"


InputInfo::InputInfo()
{
	inputInfo.setString("Mouse 1: Place start\n"
		"Mouse 2: Place end\n"
		"Esc: Exit");
	inputInfo.setColor(sf::Color::White);
}


InputInfo::~InputInfo()
{
}

void InputInfo::Draw(sf::RenderWindow& _window)
{
	_window.draw(inputInfo);
}

