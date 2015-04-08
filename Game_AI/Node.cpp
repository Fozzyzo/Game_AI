#include "Node.h"


Node::Node()
{
}


Node::~Node()
{
}

Node::Node(sf::Vector2f _pos, sf::Texture& _tex, float _cost)
{
	texture = _tex;
	position = _pos;
	sprite.setTexture(_tex);
	sprite.setPosition(_pos);
	cost = _cost;
}

void Node::Draw(sf::RenderWindow& _window)
{
	_window.draw(sprite);
}
