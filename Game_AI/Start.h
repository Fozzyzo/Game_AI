#pragma once
#include <SFML\Graphics.hpp>

class Start
{
public:
	Start();
	~Start();
	void Update(sf::RenderWindow& _window);
	void Draw(sf::RenderWindow& _window);
	void setStartPos(sf::Vector2f _pos);
	sf::Vector2f getClickPosition() { return clickPosition; }

private:

	sf::Vector2f position;
	sf::Vector2f clickPosition;
	sf::CircleShape shape;
	bool mouseClicked;
	bool isPlaced;
};

