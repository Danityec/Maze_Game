#pragma once
#include "Algorithm.h"
#include "Heuristics.h"

class Searchable 
{
public:
    Searchable(){};
    ~Searchable(){};
    virtual string* search(CommonSearcher *alg, Heuristics *h, Maze *maze) = 0;
};

class MazeSearchable : public Searchable
{
public:
    MazeSearchable(){};
    ~MazeSearchable(){};
    static double pathCost() { return 1; };
    string* search(CommonSearcher *alg, Heuristics *h, Maze *maze)
    {
        string *sol = new string; 
        sol = alg->search(h, maze); 
        return sol;
    };
};


