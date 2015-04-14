#include <SFML/Graphics.hpp>
#include "Node.h"
#include "MapLoader.h"
#include "Pathfinding.h"
#include "InputInfo.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 640), "GameAI");
	MapLoader map;
	sf::Font font;
	sf::Text inputInfo;
	sf::Image image;
	sf::Texture texture;
	sf::Vector2f pos;

	font.loadFromFile("assets/arial.ttf");

	inputInfo.setFont(font);
	inputInfo.setString("Mouse 1: Place start\n"
		"Mouse 2: Place end\n"
		"Esc: Exit");

	inputInfo.setPosition(5,0);
	inputInfo.setColor(sf::Color::White);
	inputInfo.setCharacterSize(20);

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
	//sf::Vector2f goalDirection(0.5,-0.5);
	//float distance = 140;
	//Pathfinding pt(map.mapNodes[0], map.mapNodes[99],goalDirection *= distance);
	
	sf::Vector2f goalDirection(1,0);
	float distance = 100;
	Pathfinding pt(map.mapNodes[30], map.mapNodes[39],goalDirection *= distance);
	
	bool done = false, spaceUp = true;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close(); 
			
			if(event.type == sf::Event::KeyReleased)
				spaceUp = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if(!done && spaceUp == true)
			{
 				done = pt.step();
				spaceUp = false;
			}
		}
		
		
		window.clear(sf::Color::Black);
		map.Update(window);
		map.Draw(window);
		window.draw(inputInfo);
		window.display();
	}

	return 0;
}
