#include "Start.h"


Start::Start()
{
	shape.setRadius(10.0f);
	shape.setFillColor(sf::Color(100, 250, 50));

	shape.setOutlineThickness(2.0f);
	shape.setOutlineColor(sf::Color(50, 255, 25));
}

Start::~Start()
{
}

void Start::Draw(sf::RenderWindow& _window)
{
	_window.draw(shape);
}

//void setStartPos(sf::Vector2f _pos)
