#include "Invoker.h"
using namespace std;
 
void Invoker::execute(vector<string> parameters)
{
    auto it = commMap.find(parameters[0]);
    parameters.erase(parameters.begin());
    if (it != commMap.end())
        it->second->execute(parameters);
}

void Invoker::add(string name)
{
    if (name == "exit")
    {
        ExitComm* exitComm = new ExitComm(&Cmap);
        auto pair = make_pair(name, exitComm);
        commMap.insert(pair);
    }
    else if (name == "dir")
    {
        DirComm* dirComm = new DirComm(&Cmap);
        auto pair = make_pair(name, dirComm);
        commMap.insert(pair);
    }
    else if (name == "generate")
    {
        GenerateComm* generateComm = new GenerateComm(&Cmap);
        auto pair = make_pair(name, generateComm);
        commMap.insert(pair);
    }
    else if (name == "display")
    {
        DisplayMazeComm* displayMComm = new DisplayMazeComm(&Cmap);
        auto pair = make_pair(name, displayMComm);
        commMap.insert(pair);
    }
    else if (name == "solution")
    {
        DisplaySolutionComm* displaySComm = new DisplaySolutionComm(&Cmap);
        auto pair = make_pair(name, displaySComm);
        commMap.insert(pair);
    }
    else if (name == "save")
    {
        SaveComm* saveComm = new SaveComm(&Cmap);
        auto pair = make_pair(name, saveComm);
        commMap.insert(pair);
    }
    else if (name == "load")
    {
        LoadComm* loadComm = new LoadComm(&Cmap);
        auto pair = make_pair(name, loadComm);
        commMap.insert(pair);
    }
    else if (name == "maze")
    {
        MazeSizeComm* mSizeComm = new MazeSizeComm(&Cmap);
        auto pair = make_pair(name, mSizeComm);
        commMap.insert(pair);
    }
    else if (name == "file")
    {
        FsizeComm* fSizeComm = new FsizeComm(&Cmap);
        auto pair = make_pair(name, fSizeComm);
        commMap.insert(pair);
    }
    else if (name == "solve")
    {
        SolveComm* solveComm = new SolveComm(&Cmap);
        auto pair = make_pair(name, solveComm);
        commMap.insert(pair);
    }
}