#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Position 
{
private:
    int _x;
    int _y;
public:
    Position() { _x=0; _y=0; };
    Position(int x, int y) { _x=x; _y=y; };
    ~Position(){};
    int getPositionX() { return _x; };
    int getPositionY() { return _y; };
    void setPositionX(int x) { _x = x; };
    void setPositionY(int y) { _y = y; };
    Position& operator=(const Position &a) {  if(&a == this) return *this; _x = a._x; _y = a._y; return *this; };
    bool operator==(Position a)
    {
        if((a._x == this->_x) && (a._y == this->_y))
            return true;
        else 
            return false;
    }
    bool operator!=(Position a)
    {
        if((a._x == this->_x) && (a._y == this->_y))
            return false;
        else 
            return true;
    }
    bool operator<(const Position& other) const
	{
		string one = to_string(this->_x) + to_string(this->_y);
		string two = to_string(other._x) + to_string(other._y);
		bool ans = one < two;
		return ans;
	}
};

class Maze
{
public:
    Maze(){};
    ~Maze(){};
    virtual Position getStartPosition() = 0;
    virtual Position getGoalPosition() = 0;
    virtual Position getCurrPosition() = 0;
    virtual string* getPossibleMoves() = 0;
    virtual string* getPossibleMoves(Position pos) = 0;
    virtual int sizeOfMaze() =0;
    virtual int getSize() =0;
    virtual void setPosition(Position pos, char c) =0;
    virtual char getPosition(Position pos) =0;
    virtual void setStartPosition(Position pos) =0;
    virtual void setGoalPosition(Position pos) =0;
    virtual void setCurrPosition(Position pos) =0;

    virtual string* getData() =0;
};

class Maze2D : public Maze
{ 
private:
    char** maze;
    int size;
    Position goal;
    Position start;
    Position curr;
public:
    Maze2D(int s);
    Maze2D(){};
    ~Maze2D();
    string* getPossibleMoves();
    string* getPossibleMoves(Position pos);
    int getSize() { return size; };
    int sizeOfMaze() { return((size*size) + sizeof(size) + sizeof(goal) + sizeof(start) + sizeof(curr) ); };
    void setPosition(Position pos, char c);
    char getPosition(Position pos) { return (maze[pos.getPositionX()][pos.getPositionY()]); };
    Position getStartPosition() { return start; };
    Position getGoalPosition() { return goal; };
    Position getCurrPosition() { return curr; };
    void setStartPosition(Position pos) { start = pos; };
    void setGoalPosition(Position pos) { goal = pos; };
    void setCurrPosition(Position pos) { curr = pos; };

    string* getData();
};
