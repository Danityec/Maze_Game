#pragma once
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "Maze.h"
using namespace std;

class FileHandler
{
public:
    FileHandler(){};
    ~FileHandler(){};
    vector<char> compress(Maze* maze);
    pair<Maze2D*, string*>* decompress(string* comp_maze);
    void save(Maze* maze, string *solution, string name);
    pair<Maze2D*, string*>* load(string name);
    bool hasEnding (string str, string end);
};
