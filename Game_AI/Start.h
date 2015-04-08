#pragma once
#include <SFML\Graphics.hpp>
class Start
{
public:
	Start();
	~Start();
	void Draw(sf::RenderWindow& _window);
	void setStartPos(sf::Vector2f _pos);

private:
	sf::Vector2f position;
	sf::CircleShape shape;
};

