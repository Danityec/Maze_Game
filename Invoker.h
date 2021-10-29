#pragma once 
#include "Commander.h"
#include "CacheMap.h"
#include <map>
#include <string>
using namespace std;

class Invoker
{
private:
    CacheMap Cmap;
    map<string, ICommand*> commMap;
public:
    Invoker(){};
    ~Invoker(){};
    void add(string name);
    void execute(vector<string> parameters); 
};