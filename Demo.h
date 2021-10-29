#pragma once
#include <stdio.h>
#include "Commander.h"

class Demo
{
public:
    Demo(){};
    ~Demo(){};
    void run(int size)
    {
        Print *print = new Print;

        My2DMazeGenerator MMG;
        Maze2D maze = MMG.generate(size);

        print->display2DMaze(&maze);
        print->print("\n");

        string *solution_bfs = new string;
        string *solution_astar_man = new string;
        string *solution_astar_arial = new string;

        MazeSearchable *MS;
        AirialDistance *arial = new AirialDistance;
        ManhattanDistance *manhattan = new ManhattanDistance;
        BestFirstSearch *bfs = new BestFirstSearch;
        Astar *astar1 = new Astar;
        Astar *astar2 = new Astar;

        solution_bfs = MS->search(bfs, nullptr, &maze);
        print->print(*solution_bfs);
        print->print("\n");
        print->print("number of nodes bfs: ");
        print->print(to_string(bfs->numOfNodes()));
        print->print("\n");

        solution_astar_man = MS->search(astar1, manhattan, &maze);
        print->print(*solution_astar_man);
        print->print("\n");
        print->print("number of nodes astar manhattan: ");
        print->print(to_string(astar1->numOfNodes()));
        print->print("\n");

        solution_astar_arial = MS->search(astar2, arial, &maze);
        print->print(*solution_astar_arial);
        print->print("\n");
        print->print("number of nodes astar arial: ");
        print->print(to_string(astar2->numOfNodes()));
        print->print("\n");

        delete print, solution_bfs, solution_astar_man, solution_astar_arial, arial, manhattan, bfs, astar1, astar2;
    }
};