#include "End.h"

#include <iostream>
#include "Start.h"


End::End()
{
	shape.setRadius(32.0f);
	shape.setFillColor(sf::Color(250, 100, 50));

	shape.setOutlineThickness(5.0f);
	shape.setOutlineColor(sf::Color(75, 25, 25));

	clickPosition = sf::Vector2f(0, 0);
	isPlaced = false;
}

End::~End()
{
}

void End::Update(sf::RenderWindow& _window)
{

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{

		if (mouseClicked == false)
		{
			clickPosition = sf::Vector2f(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y);
			std::cout << "x = " << clickPosition.x << ", y = " << clickPosition.y << std::endl;
			mouseClicked = true;
			isPlaced = true;
		}
	}

	else
	{
		mouseClicked = false;
	}
}

void End::Draw(sf::RenderWindow& _window)
{
	if (isPlaced == true)
	{
		_window.draw(shape);
	}
}

void End::setStartPos(sf::Vector2f _pos)
{
	shape.setPosition(_pos);
}
