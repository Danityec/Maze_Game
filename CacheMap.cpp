#include "CacheMap.h"

string *CacheMap::findSolution(string *name)
{
    it = map.find(*name);
    if (it != map.end())
        return (it->second.second);
    return nullptr;
}

Maze *CacheMap::findMaze(string *name)
{
    it = map.find(*name);
    if (it != map.end())
        return (it->second.first);
    return nullptr;
}

bool CacheMap::insertMaze(string name, Maze *maze)
{
    if (map.find(name) == map.end())
    {
        string *sol = new string;
        sol = nullptr;
        auto pair_1 = make_pair(maze, sol);
        auto pair_2 = make_pair(name, pair_1);
        map.insert(pair_2);
        delete sol;
        return true;
    }
    return false;
}

void CacheMap::insertSolution(string name, string *solution)
{
    it = map.find(name);
    if (it != map.end())
        it->second.second = solution;
    else
        cout << "The Name " << name << " already exists, choose another name" << endl;
}
