#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "Node.h"
class MapLoader
{
public:
	MapLoader();
	~MapLoader();
	void Load();
	void Draw(sf::RenderWindow &_window);
	void InitMap(int _array[100]);

public:

	std::vector<Node*>mapNodes;
	sf::Image grass;
	sf::Image wall;
	sf::Texture grassTexture;
	sf::Texture wallTexture;
};

