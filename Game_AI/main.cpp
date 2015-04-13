#include <SFML/Graphics.hpp>
#include "Node.h"
#include "MapLoader.h"
#include "Pathfinding.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 640), "SFML works!");
	MapLoader map;
	Start start;
	sf::Image image;
	sf::Texture texture;
	sf::Vector2f pos;
	sf::Sprite sprite;
	
	int mapArray[100] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	map.InitMap(mapArray);
	Pathfinding pt(map.mapNodes[0], map.mapNodes[99],140);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		//bool done = pt.step();
		window.clear(sf::Color::Black);
		start.Update(window);
		map.Update(start, window);		
		map.Draw(window);
		start.Draw(window);
		window.draw(sprite);
		window.display();
	}

	return 0;
}
