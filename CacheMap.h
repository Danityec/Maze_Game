#pragma once
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include "Maze.h"
using namespace std;

class CacheMap
{
private:
    map<string, pair<Maze*,string*>> map;
    std::map<string, pair<Maze*,string*>>::iterator it;
public:
    CacheMap(){};
    ~CacheMap(){};
    string* findSolution(string* name);
    Maze* findMaze(string* name);
    bool insertMaze(string name, Maze* maze);
    void clear() { map.clear(); }
    void insertSolution(string name, string* solution);    
};

