#include "Generator.h"
using namespace std;

string Maze2DGenerator::measureAlgorithmTime(int s)
{
    auto t_start = std::chrono::high_resolution_clock::now();

    generate(s);

    auto t_end = std::chrono::high_resolution_clock::now();
    double time_diff = std::chrono::duration<double, std::milli>(t_end-t_start).count();

    return(to_string(time_diff));
}

Maze2D My2DMazeGenerator::generate(int s)
{
    Maze2D maze(s);
    int size = maze.getSize();

    // find start position
    int r = rand() % size;
    while (r % 2 == 0)
        r = rand() % size;
    
    int c = rand() % size;
    while (c % 2 == 0)
        c = rand() % size;
 
    maze.setPosition(Position(r,c),'S');
    Position start(r, c);
    maze.setStartPosition(start);

    recursive(r, c, &maze);

    // find end position
    r = rand() % size;
    while (r % 2 == 0)
        r = rand() % size;

    c = rand() % size;
    while (c % 2 == 0)
        c = rand() % size;

    int flag = 0;
    while (flag == 0)
    {
        r = rand() % size;
        while (r % 2 == 0)
            r = rand() % size;

        c = rand() % size;
        while (c % 2 == 0)
            c = rand() % size;

        if (maze.getPosition(Position(r,c)) == '0')
        {
            flag = 1;
            maze.setPosition(Position(r,c), 'G');
            Position goal(r, c);
            maze.setGoalPosition(goal);
        }
    }
    return maze;
}

void My2DMazeGenerator::recursive(int r, int c, Maze2D* maze)
{
    array<int, 4> directions= generateRandomDirections();
    int size = maze->getSize();

    for (int i = 0; i < 4; i++)
    {
        switch (directions[i])
        {
        case 1: // Up
            if (r - 2 <= 0)
                continue;
            if (maze->getPosition(Position(r-2,c))== '1')
            {
                maze->setPosition(Position(r-2,c),'0');
                maze->setPosition(Position(r-1,c),'0');
                recursive(r - 2, c, maze);
            }
            break;
        case 2: // Right
            if (c + 2 >= size - 1)
                continue;
            if (maze->getPosition(Position(r,c+2)) == '1')
            {
                maze->setPosition(Position(r,c+2), '0');
                maze->setPosition(Position(r,c+1), '0');
                recursive(r, c + 2, maze);
            }
            break;
        case 3: // Down
            if (r + 2 >= size - 1)
                continue;
            if (maze->getPosition(Position(r+2,c)) == '1')
            {
                maze->setPosition(Position(r+2,c), '0');
                maze->setPosition(Position(r+1,c), '0');
                recursive(r + 2, c, maze);
            }
            break;
        case 4: // Left
            if (c - 2 <= 0)
                continue;
            if (maze->getPosition(Position(r,c-2)) == '1')
            {
                maze->setPosition(Position(r,c-2), '0');
                maze->setPosition(Position(r,c-1), '0');
                recursive(r, c - 2, maze);
            }
            break;
        }
    }
}

array<int, 4> My2DMazeGenerator::generateRandomDirections()
{
    array<int, 4>  directions{ 1, 2, 3, 4 };
    int seed = rand();

    shuffle(directions.begin(), directions.end(), default_random_engine(seed));

    return directions;
}

Maze2D Simple2DMazeGenerator::generate(int s)
{
    Maze2D maze(s);
    int size = maze.getSize();

    Position start;
    Position goal;
    srand(time(NULL));

    int direction = rand() % 2;
    if (direction == 0)
    {
        int random = (rand() % (size - 2)) + 1;
        Position start(random, 1);
        maze.setStartPosition(start);
        maze.setPosition(Position(random,1),'S');
        start.setPositionX(random);
        start.setPositionY(1);
        int prev = random;

        for (int i = 2; i < size - 1; ++i)
        {
            maze.setPosition(Position(prev,i),'0');
            int numOfPassages = rand() % (size - 2);

            while (numOfPassages-- > 0)
            {
                random = (rand() % (size - 2)) + 1;
                if (random - 1 == prev || random + 1 == prev)
                {
                    maze.setPosition(Position(random,i),'0');
                    prev = random;
                }
            }
        }

        Position goal(prev, size - 2);
        maze.setGoalPosition(goal);
        maze.setPosition(Position(prev,size-2),'G');
        goal.setPositionX(prev);
        goal.setPositionY(size - 2);
    }
    if (direction == 1)
    {
        int random = (rand() % (size - 2)) + 1;
        Position start(1, random);
        maze.setStartPosition(start);
        maze.setPosition(Position(1,random),'S');
        start.setPositionX(1);
        start.setPositionY(random);
        int prev = random;

        for (int i = 2; i < size - 1; ++i)
        {
            maze.setPosition(Position(i,prev),'0');
            int numOfPassages = rand() % (size - 2);

            while (numOfPassages-- > 0)
            {
                random = (rand() % (size - 2)) + 1;
                if (random - 1 == prev || random + 1 == prev)
                {
                    maze.setPosition(Position(i,random),'0');
                    prev = random;
                }
            }
        }
        
        Position goal(size - 2, prev);
        maze.setGoalPosition(goal);
        maze.setPosition(Position(size-2, prev),'G');
        goal.setPositionX(size - 2);
        goal.setPositionY(prev);
    }

    for(int i=0; i < ((size*size)/2) ; i++)
    {
        int random1 = (rand() % (size - 2)) + 1;
        int random2 = (rand() % (size - 2)) + 1;

        if (maze.getPosition(Position(random1, random2)) == '1')
            maze.setPosition(Position(random1, random2), '0');
    }
    return maze;
}