#include "MapLoader.h"


MapLoader::MapLoader()
{
	grass.loadFromFile("assets/grass.png");
	grassTexture.loadFromImage(grass);

	wall.loadFromFile("assets/wall.png");
	wallTexture.loadFromImage(wall);
}

MapLoader::~MapLoader()
{
}

void MapLoader::InitMap(int _array[100])
{		
	int columnIndex = 0;
	int rowIndex = 0;

	for (int i = 0; i < 100; i++)
	{
		switch (_array[i])
		{
		case 0:
			mapNodes.push_back(new Node(sf::Vector2f(64.0f*rowIndex, 64.0f*columnIndex), grassTexture, 1.0));
			break;

		case 1:
			mapNodes.push_back(new Node(sf::Vector2f(64.0f*rowIndex, 64.0f*columnIndex), wallTexture, 1.0));
			break;

		default:
			break;
		}

		rowIndex++;
		if (rowIndex >= 10)
		{
			rowIndex = 0;
			columnIndex++;
		}
	}
}

void MapLoader::Draw(sf::RenderWindow &_window)
{
	for (int i = 0; i < mapNodes.size(); i++)
	{
		mapNodes[i]->Draw(_window);
	}
}
