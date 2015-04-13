#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System\Vector2.hpp>
#include <vector>
#include <map>

class Node
{
	friend class Pathfinding;
public:
	Node();
	Node(sf::Vector2f _pos, sf::Texture& _tex, float _costMultiplier);
	~Node();
	void Draw(sf::RenderWindow& _window);
	void AddConnection(Node* node, float cost);
	float getCostMultiplier(){ return costMultiplier; }
	sf::Sprite getSprite(){ return sprite; }
	sf::Vector2f getPos(){ return position; }
	sf::FloatRect getBoundingBox() { return boundingBox; }
	
private:

	sf::FloatRect boundingBox;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Texture texture;
	std::map<Node*, float> connections;
	float costMultiplier;
};

