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
		int randomI = rand() % 3 + 1;
		switch (_array[i])
		{
		case 0:
			mapNodes.push_back(new Node(sf::Vector2f(64.0f*rowIndex, 64.0f*columnIndex), grassTexture, 1.0));
			break;

		case 1:
			mapNodes.push_back(new Node(sf::Vector2f(64.0f*rowIndex, 64.0f*columnIndex), wallTexture, -1.0));
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

	rowIndex = 0;
	columnIndex = 0;
	
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			switch (j)
			{
			case 0:
				if (rowIndex > 0 && columnIndex > 0)
				{
					if (mapNodes[i - 11]->getCostMultiplier() > 0)
						mapNodes[i]->AddConnection(mapNodes[i - 11], sf::Vector2f(-1,1) *= (14 * mapNodes[i - 11]->getCostMultiplier()));
				}
				break;

			case 1:
				if (columnIndex > 0)
				{
					if (mapNodes[i - 10]->getCostMultiplier() > 0)
						mapNodes[i]->AddConnection(mapNodes[i - 10], sf::Vector2f(0,1) *= (10 * mapNodes[i - 10]->getCostMultiplier()));
				}
				break;
			case 2:
				if (columnIndex > 0 && rowIndex < 9)
				{
					if (mapNodes[i - 9]->getCostMultiplier() > 0)
						mapNodes[i]->AddConnection(mapNodes[i - 9], sf::Vector2f(1,1) *= (14 * mapNodes[i - 9]->getCostMultiplier()));
				}
				break;
			case 3:
			{
				if (rowIndex > 0)
				{
					if (mapNodes[i - 1]->getCostMultiplier() > 0)
						mapNodes[i]->AddConnection(mapNodes[i - 1], sf::Vector2f(-1,0) *= (10 * mapNodes[i - 1]->getCostMultiplier()));
				}
				break;
			case 4:
				if (rowIndex < 9)
				{
					if (mapNodes[i + 1]->getCostMultiplier() > 0)
						mapNodes[i]->AddConnection(mapNodes[i + 1], sf::Vector2f(1,0) *= (10 * mapNodes[i + 1]->getCostMultiplier()));
					
				}
				break;

			case 5:
				if (columnIndex < 9 && rowIndex > 0)
				{
					if (mapNodes[i + 9]->getCostMultiplier() > 0)
						mapNodes[i]->AddConnection(mapNodes[i + 9], sf::Vector2f(-1,-1) *= (14 * mapNodes[i + 9]->getCostMultiplier()));

				}
				break;
			case 6:
				if (columnIndex < 9)
				{
					if (mapNodes[i + 10]->getCostMultiplier() > 0)
						mapNodes[i]->AddConnection(mapNodes[i + 10], sf::Vector2f(0,-1) *= (10 * mapNodes[i + 10]->getCostMultiplier()));
					
				}
				break;
			case 7:
				if (rowIndex < 9 && columnIndex < 9)
				{
					if (mapNodes[i + 11]->getCostMultiplier() > 0)
						mapNodes[i]->AddConnection(mapNodes[i + 11], sf::Vector2f(1,-1) *=(14 * mapNodes[i + 11]->getCostMultiplier()));
					
				}
				break;

			default:
				break;
			}
			
			}
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

	start.Draw(_window);
	end.Draw(_window);
}

void MapLoader::Update(sf::RenderWindow& _window)
{
	start.Update(_window);
	end.Update(_window);

	for (int i = 0; i < mapNodes.size(); i++)
	{
		if (start.getClickPosition().x >= mapNodes[i]->getPos().x
			&& start.getClickPosition().y >= mapNodes[i]->getPos().y
			&& start.getClickPosition().x <= mapNodes[i]->getPos().x + 64.0f
			&& start.getClickPosition().y <= mapNodes[i]->getPos().y + 64.0f)
		{
			start.setStartPos(sf::Vector2f(mapNodes[i]->getPos().x, mapNodes[i]->getPos().y));
		}
	}

	for (int i = 0; i < mapNodes.size(); i++)
	{
		if (end.getClickPosition().x >= mapNodes[i]->getPos().x
			&& end.getClickPosition().y >= mapNodes[i]->getPos().y
			&& end.getClickPosition().x <= mapNodes[i]->getPos().x + 64.0f
			&& end.getClickPosition().y <= mapNodes[i]->getPos().y + 64.0f)
		{
			end.setStartPos(sf::Vector2f(mapNodes[i]->getPos().x, mapNodes[i]->getPos().y));
		}
	}
}

