#include "Maze.h"

Maze2D::Maze2D(int s)
{
    if (s % 2 == 0)
        s++;
    
    size = s;

    maze = new char*[size];
    for (int i=0; i < size; i++)
        maze[i] = new char[size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            maze[i][j] = '1';
}

Maze2D::~Maze2D()
{
    for (int i=0; i < size; i++)
        delete[] maze[i];
    delete[] maze;
}

void Maze2D::setPosition(Position pos, char c)
{
    if (pos.getPositionX() > size || pos.getPositionX() < 0)
        return;
    if (pos.getPositionY() > size || pos.getPositionY() < 0)
        return;

    maze[pos.getPositionX()][pos.getPositionY()] = c;
}

string* Maze2D::getPossibleMoves()
{
    string *pos_moves = new string;
    int x = curr.getPositionX();
    int y = curr.getPositionY();
    if( maze[x-1][y] != '1')
        *pos_moves += 'U';
    if( maze[x+1][y] != '1')
        *pos_moves += 'D';
    if( maze[x][y-1] != '1')
        *pos_moves += 'L';
    if( maze[x][y+1] != '1')
        *pos_moves += 'R';

    return pos_moves;
}


string* Maze2D::getPossibleMoves(Position pos)
{
    string *pos_moves = new string;
    int x = pos.getPositionX();
    int y = pos.getPositionY();

    if( maze[x-1][y] != '1')
        *pos_moves += 'U';
    if( maze[x+1][y] != '1')
        *pos_moves += 'D';
    if( maze[x][y-1] != '1')
        *pos_moves += 'L';
    if( maze[x][y+1] != '1')
        *pos_moves += 'R';

    return pos_moves;
}

string* Maze2D::getData()
{
    string* str = new string;

    *str += to_string(size);
    *str += " ";

    for(int i=0; i < size; i++)
        for(int j=0; j < size; j++)
            *str += maze[i][j];
    
    return str;
}