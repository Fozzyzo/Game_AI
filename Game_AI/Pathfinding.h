#pragma once
#include "Node.h"
#include <vector>
#include <map>

class Path
{
	friend class Pathfinding;
public:
	Path(Node * from, Node * to, float estCost){};
	~Path(){};

private:
	Node * from;
	Node * to;
	float cost;
	float estimatedTotalCost;
};

class Pathfinding
{
public:
	Pathfinding(Node * start, Node * end, float distanceToEnd):start(start),end(end),currentCost(distanceToEnd)
	{
		for(it = start->connections.begin(); it != start->connections.end(); it++)
		{
			openNodes.push_back(new Path(start,it->first,distanceToEnd - it->second));
		}

	};
	bool step()
	{
		Path * shortest = *openNodes.begin();
		Path * current;
		for(std::vector<Path*>::iterator pathIter = openNodes.begin(); pathIter != openNodes.end(); pathIter++)
		{
			if(pathIter == openNodes.begin())
				shortest = *pathIter;
			else
			{
				if( (*pathIter)->estimatedTotalCost < shortest->estimatedTotalCost )
					shortest = *pathIter;
			}
		}
		currentPath.push_back(shortest);
		if(shortest->to == end)
			return true;
		currentCost -= shortest->cost;
		for(std::vector<Path*>::iterator pathIter = openNodes.begin(); pathIter != openNodes.end(); pathIter++)
			if(*pathIter != shortest)
				closedNodes.push_back(*pathIter);
		openNodes.empty();
		for(it = shortest->to->connections.begin(); it != shortest->to->connections.end(); it++)
		{
			Node * nd = it->first;
			Path * p = new Path(shortest->to,it->first,currentCost - it->second);
			openNodes.push_back(p);
		}
		return false;
	}
	~Pathfinding(){};

private:
	Node * start;
	Node * end;
	float currentCost;
	std::map<Node*, float>::iterator it;
	std::vector<Path*> openNodes;
	std::vector<Path*> closedNodes;
	std::vector<Path*> currentPath;
};
