#include <iostream>
#include "Start.h"


Start::Start()
{
	shape.setRadius(25.0f);
	shape.setFillColor(sf::Color(100, 250, 50));

	shape.setOutlineThickness(5.0f);
	shape.setOutlineColor(sf::Color(25, 75, 25));

	isPlaced = false;
}

Start::~Start()
{
}

void Start::Update(sf::RenderWindow& _window)
{

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		
		if (mouseClicked == false)
		{		
			clickPosition = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
			//shape.setPosition(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y);			
			std::cout << "x = " << sf::Mouse::getPosition(_window).x << ", y = " << sf::Mouse::getPosition(_window).y << std::endl;
			mouseClicked = true;
			isPlaced = true;
		}
	}

	else
	{
		mouseClicked = false;
	}
}

void Start::Draw(sf::RenderWindow& _window)
{
	if (isPlaced == true)
	{
		_window.draw(shape);
	}
}

void Start::setStartPos(sf::Vector2f _pos)
{
	shape.setPosition(_pos);
}


