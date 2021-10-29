#include "FileHandler.h"
vector<char> FileHandler::compress(Maze *maze)
{
    vector<char> comp_maze;
    string *str = new string;
    str = maze->getData();

    char *Cstr = new char[str->length() + 1];
    strcpy(Cstr, str->c_str());

    int count = 0;
    int j = 0;
    while (Cstr[j] != ' ')
    {
        comp_maze.push_back(Cstr[j]);
        j++;
    }
    for (int i = j + 1; i <= str->length();)
    {
        comp_maze.push_back(' ');
        if (Cstr[i] == '0')
        {
            comp_maze.push_back('0');

            while ((i < str->length()) && (Cstr[i] == '0'))
            {
                count++;
                i++;
            }
            char c[4];
            itoa(count, c, 10);
            comp_maze.push_back(c[0]);
            if (count > 9)
                comp_maze.push_back(c[1]);
            if (count > 99)
                comp_maze.push_back(c[2]);
            count = 0;
        }
        else if (Cstr[i] == '1')
        {
            comp_maze.push_back('1');

            while ((i < str->length()) && (Cstr[i]) == '1')
            {
                count++;
                i++;
            }
            char c[4];
            itoa(count, c, 10);
            comp_maze.push_back(c[0]);
            if (count > 9)
                comp_maze.push_back(c[1]);
            if (count > 99)
                comp_maze.push_back(c[2]);
            count = 0;
        }
        else
            comp_maze.push_back(Cstr[i++]);
    }
    delete Cstr, str;
    return comp_maze;
}

pair<Maze2D*, string*>* FileHandler::decompress(string *comp_maze)
{
    char *Cstr = new char[comp_maze->length() + 1];
    strcpy(Cstr, comp_maze->c_str());

    string *solution = new string;
    int flag =0;

    vector<char> tmp_maze;

    int j = 0;
    string Ssize;
    string Scount;

    while (Cstr[j] != ' ')
    {
        Ssize += Cstr[j];
        j++;
    }
    int size = stoi(Ssize, nullptr);

    for (int i = j, k = 0; i < comp_maze->length() + 1; i++, k++)
    {
        Scount.clear();
        if (Cstr[i] == '$' )
        {
            while ( i < comp_maze->length() + 1 )
            {
                flag =1;
                i++;
                solution->push_back(Cstr[i]);
            }
        }
        else if (Cstr[i] == '0')
        {
            i++;
            while (Cstr[i] != ' ')
                Scount += Cstr[i++];
            j = stoi(Scount, nullptr, 10);
            for (; j > 0; j--)
                tmp_maze.push_back('0');
        }
        else if (Cstr[i] == '1')
        {
            i++;
            while (Cstr[i] != ' ')
                Scount += Cstr[i++];
            j = stoi(Scount, nullptr);
            for (; j > 0; j--)
                tmp_maze.push_back('1');
        }
        else if (Cstr[i] == 'S')
            tmp_maze.push_back('S');
        else if (Cstr[i] == 'G')
            tmp_maze.push_back('G');
    }

    char *tmp_maze2 = new char[tmp_maze.size() + 1];
    for (int i = 0; i < tmp_maze.size() + 1; i++)
        tmp_maze2[i] = tmp_maze[i];

    Maze2D *maze = new Maze2D(size);
    for (int k = 0; tmp_maze2[k];)
        for (int x = 0; x < size; x++)
            for (int y = 0; y < size; y++)
            {
                if (tmp_maze2[k] == 'S')
                    maze->setStartPosition(Position(x, y));
                else if (tmp_maze2[k] == 'G')
                    maze->setGoalPosition(Position(x, y));

                maze->setPosition(Position(x, y), tmp_maze2[k++]);
            }

    delete[] Cstr, tmp_maze2;
    
    pair<Maze2D*, string*>* pair;
    if(flag ==0)
        *pair = make_pair(maze, nullptr);
    else  
        *pair = make_pair(maze, solution);
    return pair;
}

void FileHandler::save(Maze *maze, string *solution, string name)
{
    vector<char> comp_maze = compress(maze);

    char *maze_str = new char[comp_maze.size() + 1];
    for (int i = 0; i < comp_maze.size() + 1; i++)
        maze_str[i] = comp_maze[i];

    if (!hasEnding(name, ".txt"))
        name += ".txt";
    char *fname = new char[name.length() + 1];
    strcpy(fname, name.c_str());
    FILE *outfile;
    outfile = fopen(fname, "w");
    std::ofstream file;
    file.open(fname);
    file << maze_str;
    if (solution)
    {
        file << "$";
        file << *solution;
    }
    file.close();
    fclose(outfile);
    delete fname, maze_str;
}

pair<Maze2D*, string*>* FileHandler::load(string name)    
{
    string *str = new string;
    if (!hasEnding(name, ".txt"))
        name += ".txt";
    const char *fname = name.c_str();
    FILE *infile;
    infile = fopen(fname, "r");
    std::ifstream file;
    file.open(fname);
    getline(file, *str);

    file.close();
    fclose(infile);
    delete fname;
    return (decompress(str));
}

bool FileHandler::hasEnding(string str, string end)
{
    if (str.length() >= end.length())
        return (0 == str.compare(str.length() - end.length(), end.length(), end));
    else
        return false;
}
