#pragma once
#include <iostream>
#include "Maze.h"
using namespace std;

class Print
{
public:
    Print(ostream &_out = cout, istream &_in = cin): in(_in), out(_out){};
    ~Print(){};
    void display2DMaze(Maze* maze);
    void displaySolution(string* solution);
    void print(string str) { out << str; };
private:
    ostream &out; 
    istream &in;
};