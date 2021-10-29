#pragma once
#include <stdio.h>
#include <queue>
#include <map>
#include <algorithm>
#include "Node.h"
#include "Heuristics.h"

class Algorithm
{
public:
    Algorithm(){};
    ~Algorithm(){};
};

class Searcher : public Algorithm
{
public:
    Searcher(){};
    ~Searcher(){};
    virtual string* search(Heuristics *heuristic, Maze *maze) =0;
};

class CommonSearcher : public Searcher
{
public:
    CommonSearcher(){};
    ~CommonSearcher(){};
    int numOfNodes() { return closedList.size(); }; 
    virtual string* search(Heuristics *heuristic, Maze *maze) =0;
    bool openListCheck(Position* pos, double f);
protected:
    std::priority_queue<Node*, std::vector<Node*>, myComperator> openList;
    std::priority_queue<Node*, std::vector<Node*>, myComperator> closedList;
    std::map<pair<int, int>,double> mapOpenList;
    std::map<pair<int, int>,double>::iterator it_mapOpenList;
};

class Astar : public CommonSearcher
{
public:
    Astar(){};
    ~Astar(){};
    double f(double h, double g, double cost);
    string* search(Heuristics *heuristic, Maze *maze);
};

class BestFirstSearch : public CommonSearcher
{
public:
    BestFirstSearch(){}; 
    ~BestFirstSearch(){};
    double f(double g);
    string* search(Heuristics *heuristic, Maze *maze);
};