#pragma once
#include <stdio.h>
#include <math.h>
#include "Maze.h"

class Heuristics
{
public:
    Heuristics(){};
    ~Heuristics(){};
    virtual double estimatedCost(Position curr, Position goal) = 0;
};

class ManhattanDistance : public Heuristics
{
public:
    ManhattanDistance(){};
    ~ManhattanDistance(){};
    double estimatedCost(Position curr, Position goal);
};

class AirialDistance : public Heuristics
{
public:
    AirialDistance(){};
    ~AirialDistance(){};
    double estimatedCost(Position curr, Position goal);
};
