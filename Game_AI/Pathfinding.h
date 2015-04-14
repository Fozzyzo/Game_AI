#pragma once
#include "Node.h"
#include <vector>
#include <map>
#include <math.h>

class Path
{
	friend class Pathfinding;
public:
	
	Path(Node * from, Node * to, sf::Vector2f estCost):from(from),to(to),estimatedLength(estCost){cost = getLength();};
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
	float estimatedTotalCost;
};

class Pathfinding
{
public:
	Pathfinding(Node * start, Node * end, sf::Vector2f endVector):start(start),end(end),endVector(endVector)
	{
		sf::Vector2f currentVec;
		for(it = start->connections.begin(); it != start->connections.end(); it++)
		{
			currentVec = endVector - it->second;
			it->first->sprite.setColor(sf::Color(0,100,0,255));
			openNodes.push_back(new Path(start,it->first,currentVec));
		}

	};
	bool step()
	{
		currentCost = 0;
		Path * shortest = *openNodes.begin();
		for(std::vector<Path*>::iterator pathIter = openNodes.begin(); pathIter != openNodes.end(); pathIter++)
		{
			if(pathIter == openNodes.begin())
				shortest = *pathIter;
			else
			{
				if( (*pathIter)->getLength() < shortest->getLength() )
					shortest = *pathIter;
			}
		}
		currentPath.push_back(shortest);
		if(shortest->to == end)
			return true;
		if(shortest->getLength() <= 10)
			return true;
		currentCost -= shortest->cost;
		for(std::vector<Path*>::iterator pathIter = openNodes.begin(); pathIter != openNodes.end(); pathIter++)
		{
			if(*pathIter != shortest)
			{
				(*pathIter)->to->sprite.setColor(sf::Color(100,0,0,255));
				closedNodes.push_back(*pathIter);
			}
		}
		openNodes.clear();
		sf::Vector2f currentVec;
		for(it = shortest->to->connections.begin(); it != shortest->to->connections.end(); it++)
		{
			currentVec = shortest->estimatedLength - it->second;
			//currentVec = endVector + it->second;
			Node * nd = it->first;
			Path * p = new Path(shortest->to,it->first,currentVec);
			p->to->sprite.setColor(sf::Color(0,100,0,255));
			openNodes.push_back(p);
		}
		return false;
	}
	~Pathfinding(){};

private:
	Node * start;
	Node * end;
	sf::Vector2f endVector;
	sf::Vector2f currentVector;
	float currentCost;
	std::map<Node*, sf::Vector2f>::iterator it;
	std::vector<Path*> openNodes;
	std::vector<Path*> closedNodes;
	std::vector<Path*> currentPath;
};
