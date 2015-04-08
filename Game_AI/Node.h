#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System\Vector2.hpp>
class Node
{
public:
	Node();
	Node(sf::Vector2f _pos, sf::Texture& _tex, float _cost);
	~Node();
	void Draw(sf::RenderWindow& _window);
	sf::Sprite getSprite(){ return sprite; }
	
private:

	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Texture texture;
	float cost;
};

