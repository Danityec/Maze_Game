#pragma once
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <ctime>
#include <array>
#include <random>
#include <chrono>
#include "Maze.h"
#include "Print.h" 
using namespace std;

class IMaze2DGenerator
{
public:
    IMaze2DGenerator(){};
    ~IMaze2DGenerator(){};
    virtual Maze2D generate(int s) = 0;
    virtual string measureAlgorithmTime(int s) = 0;
};

class Maze2DGenerator : public IMaze2DGenerator
{
public:
    Maze2DGenerator(){};
    ~Maze2DGenerator(){};
    virtual Maze2D generate(int s) = 0;
    string measureAlgorithmTime(int s);
};

class My2DMazeGenerator : public Maze2DGenerator
{
public:
    My2DMazeGenerator(){};
    ~My2DMazeGenerator(){};
    Maze2D generate(int s);
    void recursive(int r, int c, Maze2D* maze);
    array<int,4> generateRandomDirections();
};

class Simple2DMazeGenerator : public Maze2DGenerator
{
public:
    Simple2DMazeGenerator(){};
    ~Simple2DMazeGenerator(){};
    Maze2D generate(int s);
    array<int,4> generateRandomDirections();
};
