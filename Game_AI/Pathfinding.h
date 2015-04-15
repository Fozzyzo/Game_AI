#pragma once
#include "Node.h"
#include <vector>
#include <map>
#include <math.h>

class Path
{
	friend class Pathfinding;
public:
	
	Path(Node * from, Node * to, sf::Vector2f estCost, sf::Vector2f vcost,float currentCost):from(from),to(to),estimatedLength(estCost)
	{
		
		cost = sqrt(powf(vcost.x,2) + powf(vcost.y,2));
		costSoFar = cost +currentCost;
		estimatedTotalCost = costSoFar + sqrt(powf(estCost.x,2) + powf(estCost.y,2));
	};
	float getLength()
	{
		return std::sqrtf((std::powf(estimatedLength.x,2) + std::powf(estimatedLength.y,2)));
	}
	~Path(){};

private:
	
	Node * from;
	Node * to;
	float cost;
	sf::Vector2f estimatedLength;
	float costSoFar;
	float estimatedTotalCost;
};

class Pathfinding
{
public:
	Pathfinding(Node * start, Node * end, sf::Vector2f endVector);
	bool step();
	~Pathfinding(){};
private:
	int findInClosedNodes(Node*);
	int findInVectorNodes(Node*toFind,std::vector<Path *> from);
	bool once;
	Node * start;
	Node * end;
	sf::Vector2f endVector;
	sf::Vector2f currentVector;
	float currentCost;
	float lengthToEnd;
	std::map<Node*, sf::Vector2f>::iterator it;
	std::vector<Path*> openNodes;
	std::vector<Path*> closedNodes;
	std::vector<Path*> currentPath;
};
class step
{
public:
	step(){};
	~step(){};

private:
	Path * path;
	float totalCost;
};