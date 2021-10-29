#include "Print.h"
using namespace std;

void Print::display2DMaze(Maze* maze)
{
    int s = maze->getSize();

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (maze->getPosition(Position(i,j)) == '1')
                cout << "||";
            if (maze->getPosition(Position(i,j)) == '0')
                cout << "  ";
            if (maze->getPosition(Position(i,j)) == 'G')
                cout << " G";
            if (maze->getPosition(Position(i,j)) == 'S')
                cout << " S";
        }
        cout << endl;
    }
}

void Print::displaySolution(string* solution)
{
    out << "( ";
    for (int i = 0; i < (solution->length()-1) ; i++)
        out << solution[i] << " , " << endl;
    out << solution[solution->length()] << " )" << endl;
}