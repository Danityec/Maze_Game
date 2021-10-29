#pragma once
#include <iostream>
#include <string>
#include "Invoker.h"
using namespace std;

class TestMazeGenerator
{
public:
    TestMazeGenerator(){};
    ~TestMazeGenerator(){};
    void testMazeGenerator(Maze2DGenerator &mg, int s)
    {
        //print the time it takes the algorithm to run
        cout << mg.measureAlgorithmTime(s) << endl;

        //generate another 2D maze
        Maze2D maze = mg.generate(s);

        //get the maze entrance
        Position p = maze.getStartPosition();

        //print the position- format{x,y}
        cout << "{" << p.getPositionX() << "," << p.getPositionY() << "}" << endl;

        //get all possible moves from a position
        string *moves = maze.getPossibleMoves(p);
        cout << *moves << endl;
        cout << "{" << maze.getGoalPosition().getPositionX() << "," << maze.getGoalPosition().getPositionY() << "}" << endl;
        
        //print the maze
        Print print(cout, cin);
        print.display2DMaze(&maze);
    }
};