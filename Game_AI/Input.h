#pragma once
#include "SFML\Window.hpp"
#include "Start.h"
class Input
{
public:
	Input();
	~Input();
	void Update(Start _start);

public:

	bool mouseReadyToClick;
	sf::Vector2f mousePos;
};

