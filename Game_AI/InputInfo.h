#pragma once
#include "SFML\Graphics.hpp"
class InputInfo
{
public:
	InputInfo();
	~InputInfo();
	void Draw(sf::RenderWindow& _window);

private:
	sf::Text inputInfo;
};

