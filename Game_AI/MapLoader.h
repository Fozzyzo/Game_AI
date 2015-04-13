#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "Start.h"
#include "End.h"
#include "Node.h"
class MapLoader
{
public:
	MapLoader();
	~MapLoader();
	void Load();
	void Draw(sf::RenderWindow &_window);
	void Update(sf::RenderWindow& _window);
	void InitMap(int _array[100]);
	sf::Vector2f getNodePos(sf::Vector2i _mousePos);

public:

	std::vector<Node*>mapNodes;
	sf::Image grass;
	sf::Image wall;
	sf::Texture grassTexture;
	sf::Texture wallTexture;
	Start start;
	End end;
	
};

