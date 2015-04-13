#include "Node.h"


Node::Node()
{
}


Node::~Node()
{
}

Node::Node(sf::Vector2f _pos, sf::Texture& _tex, float _costMultiplier)
{
	texture = _tex;
	position = _pos;
	sprite.setTexture(_tex);
	sprite.setPosition(_pos);
	costMultiplier = _costMultiplier;
	boundingBox = sprite.getGlobalBounds();
}

void Node::Draw(sf::RenderWindow& _window)
{
	_window.draw(sprite);
}

void Node::AddConnection(Node* node, float cost)
{
	connections.insert(std::make_pair(node, cost));
}
