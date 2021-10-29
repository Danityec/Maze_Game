#include "Commander.h"

void DirComm::execute(vector<string> params)
{
    DIR *_dir;
    struct dirent *entry;
    struct stat info;

    char *dir_name = new char[params[0].length() + 1];
    strcpy(dir_name, params[0].c_str());

    _dir = opendir(dir_name);
    if (!_dir)
    {
        print->print("Directory was not found\n");
        return;
    }
    vector<string> str;
    while ((entry = readdir(_dir)) != NULL)
        if (entry->d_name[0] != '.')
        {
            string path = string(dir_name) + "/" + string(entry->d_name);
            str.insert(str.begin(), path);
            print->print(path);
            print->print("\n");
            stat(path.c_str(), &info);
            if (S_ISDIR(info.st_mode))
                execute(str);
        }
    delete[] dir_name;
    closedir(_dir);
}

void GenerateComm::execute(vector<string> params) //name, size, choice
{
    bool insrt;
    string name = params[0];
    int size = stoi(params[1]);
    string choice = params[2];

    if (choice == "simple")
    {
        Simple2DMazeGenerator SMG;
        Maze2D *maze = new Maze2D(SMG.generate(size));
        insrt = map->insertMaze(name, maze);
    }
    else if (choice == "my")
    {
        My2DMazeGenerator MMG;
        Maze2D *maze = new Maze2D(MMG.generate(size));
        insrt = map->insertMaze(name, maze);
    }
    if (insrt)
    {
        print->print("Maze ");
        print->print(name);
        print->print(" is ready\n");
    }
    else
    {
        print->print("The Name ");
        print->print(name);
        print->print(" already exists\n");
    }
}

void DisplayMazeComm::execute(vector<string> params)
{
    Maze *maze = new Maze2D();
    maze = map->findMaze(&params[0]);
    print->display2DMaze(maze);
}

void SaveComm::execute(vector<string> params)
{
    Maze *maze = map->findMaze(&params[0]);
    string *solution = map->findSolution(&params[0]);
    filehandler->save(maze, solution, params[1]);
}

void LoadComm::execute(vector<string> params)
{
    auto pair = filehandler->load(params[0]);
    map->insertMaze(params[1], pair->first);
    if(pair->second != nullptr) 
        map->insertSolution(params[1], pair->second);
}

void MazeSizeComm::execute(vector<string> params)
{
    Maze *maze = map->findMaze(&params[1]);
    int s = maze->sizeOfMaze();
    print->print("Size of maze is: ");
    print->print(to_string(s));
    print->print(" bytes\n");
}

void FsizeComm::execute(vector<string> params)
{
    FILE *p_file = NULL;
    p_file = fopen(params[1].c_str(), "rb");
    fseek(p_file, 0, SEEK_END);
    int size = ftell(p_file);
    fclose(p_file);
    print->print("Size of file is: ");
    print->print(to_string(size));
    print->print(" bytes\n");
}

void SolveComm::execute(vector<string> params) //name, alg, h
{
    string heuristic;
    string name = params[0];
    string alg = params[1];
    if (alg == "astar")
        heuristic = params[2];

    string *solution = new string;
    MazeSearchable *MS = new MazeSearchable;
    AirialDistance arial;
    ManhattanDistance manhattan;
    Maze *maze = map->findMaze(&name);

    if (alg == "astar")
    {
        Astar astar;
        if (heuristic == "manhattan")
            solution = MS->search(&astar, &manhattan, maze);
        else
            solution = MS->search(&astar, &arial, maze);
    }

    if (alg == "bfs")
    {
        BestFirstSearch bfs;
        solution = MS->search(&bfs, nullptr, maze);
    }

    map->insertSolution(name, solution);
    print->print("Solution for ");
    print->print(name);
    print->print(" is ready\n");
}

void DisplaySolutionComm::execute(vector<string> params)
{
    string *s = new string;
    s = map->findSolution(&params[0]);
    print->print(*s);
    print->print("\n");
    delete s;
}

void ExitComm::execute(vector<string> params)
{
    map->clear();
    exit(0);
}


