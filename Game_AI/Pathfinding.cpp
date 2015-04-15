#include "Pathfinding.h"
Pathfinding::Pathfinding(Node * start, Node * end, sf::Vector2f endVector):start(start),end(end),endVector(endVector)
{
	once = false;
	lengthToEnd = std::sqrtf(std::powf(endVector.x,2) + std::powf(endVector.y,2));
	currentCost = 0;
	sf::Vector2f currentVec;
	float length;
	for(it = start->connections.begin(); it != start->connections.end(); it++)
	{
		currentVec = endVector - it->second;
		length = std::sqrtf(powf(it->second.x,2)+ powf(it->second.y,2));
		it->first->sprite.setColor(sf::Color(0,100,0,255));
		openNodes.push_back(new Path(start,it->first,currentVec,it->second,0));
	}

};

bool Pathfinding::step()
{ 
	Path * shortest = nullptr;
 	if(openNodes.size() != 0)
	{
		shortest = *openNodes.begin();
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
	}
	Path * clsdClosest = nullptr;
	for(std::vector<Path*>::iterator pathIter = closedNodes.begin(); pathIter != closedNodes.end(); pathIter++)
	{
		if(pathIter == closedNodes.begin())
			clsdClosest = *pathIter;
		else
		{
			if( (*pathIter)->getLength() < clsdClosest->getLength() )
				clsdClosest = *pathIter;
		}
	}
	if(openNodes.size() == 0)
		shortest = clsdClosest;
	//once = false;
	if(clsdClosest && shortest && once == false)
	{
		if(clsdClosest->estimatedTotalCost < shortest->estimatedTotalCost)
		{
			once = true;
			closedNodes.push_back(shortest);
			openNodes.clear();
			shortest = clsdClosest;
			//shortest->from->sprite.setColor(sf::Color(0,255,255,255));
			//shortest->to->sprite.setColor(sf::Color(0,255,255,255));
			//Path * p = new Path(shortest->to,it->first,currentVec,it->second,shortest->costSoFar);
			//openNodes.
		}
	}

	currentCost += shortest->cost;

	currentPath.push_back(shortest);
	shortest->from->sprite.setColor(sf::Color(0,0,100,255));
	if(shortest->to == end)
	{
		shortest->to->sprite.setColor(sf::Color(255,0,0,255));
		return true;
	}
	
	for(std::vector<Path*>::iterator pathIter = openNodes.begin(); pathIter != openNodes.end(); pathIter++)
	{
		if(*pathIter != shortest && findInVectorNodes((*pathIter)->from,currentPath))
		{
			(*pathIter)->to->sprite.setColor(sf::Color(100,0,0,255));
			closedNodes.push_back(*pathIter);
		}
	}
	openNodes.clear();
	sf::Vector2f currentVec;
	bool origin = false;
	for(it = shortest->to->connections.begin(); it != shortest->to->connections.end(); it++)
	{
		if(shortest->from == it->first)
			origin = true;
		else
			origin = false;
		if(findInClosedNodes(it->first) == -1 && origin == false && findInVectorNodes(it->first,currentPath) == -1) //currentPath == -1 pitää olla parempi ratkaisu
		{
			currentVec = shortest->estimatedLength - it->second;
			//currentVec = endVector + it->second;
			Node * nd = it->first;
			Path * p = new Path(shortest->to,it->first,currentVec,it->second,shortest->costSoFar);
			p->to->sprite.setColor(sf::Color(0,100,0,255));
			openNodes.push_back(p);
		}
	}
	return false;
}
int Pathfinding::findInClosedNodes(Node * toFind)
{
	int i = 0;
	for(std::vector<Path*>::iterator it = closedNodes.begin(); it != closedNodes.end(); it++)
	{
		if((*it)->to == toFind)
			return i;
		i++;
	}
	return -1;
}

int Pathfinding::findInVectorNodes(Node*toFind,std::vector<Path *> from)
{
	int i = 0;
	for(std::vector<Path*>::iterator it = from.begin(); it != from.end(); it++)
	{
		if((*it)->to == toFind)
			return i;
		i++;
	}
	return -1;
}