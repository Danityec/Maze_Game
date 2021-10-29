#pragma once
#include <stdio.h>
#include "dirent.h"
#include <sys/stat.h>
#include <string.h>
#include <iostream>
#include <string>
#include "FileHandler.h"
#include <filesystem>
#include <fstream>
#include "Generator.h"
#include "Searchable.h"
#include "CacheMap.h"
#include "Print.h"
using namespace std;

class ICommand
{
protected:
    CacheMap *map; 
    Print *print;
public:
    ICommand(CacheMap *_map):map(_map) {print = new Print; };
    ~ICommand() { delete print; delete map; };
    virtual void execute(vector<string> params)=0;
};

class DirComm : public ICommand
{
public:
    DirComm(CacheMap *_map):ICommand(_map){};
    ~DirComm(){};
    void execute(vector<string> params);
};

class GenerateComm : public ICommand
{
    public:
    GenerateComm(CacheMap *_map):ICommand(_map){};
    ~GenerateComm(){};
    void execute(vector<string> params);    
};

class DisplayMazeComm : public ICommand
{
    public:
    DisplayMazeComm(CacheMap *_map):ICommand(_map){};
    ~DisplayMazeComm(){};
    void execute(vector<string> params);
};

class SaveComm : public ICommand
{
private:
    FileHandler *filehandler;

public:
    SaveComm(CacheMap *_map):ICommand(_map){};
    ~SaveComm(){};
    void execute(vector<string> params);
};

class LoadComm : public ICommand
{
private:
    FileHandler *filehandler;
public:
    LoadComm(CacheMap *_map):ICommand(_map){};
    ~LoadComm(){};
    void execute(vector<string> params);
};

class MazeSizeComm : public ICommand
{
    public:
    MazeSizeComm(CacheMap *_map):ICommand(_map){};
    ~MazeSizeComm(){};
    void execute(vector<string> params);
};

class FsizeComm : public ICommand
{
public:
    FsizeComm(CacheMap *_map):ICommand(_map){};
    ~FsizeComm(){};
    void execute(vector<string> params);
};

class SolveComm : public ICommand
{
    public:
    SolveComm(CacheMap *_map):ICommand(_map){};
    ~SolveComm(){};
    void execute(vector<string> params);
};

class DisplaySolutionComm : public ICommand
{
    public:
    DisplaySolutionComm(CacheMap *_map):ICommand(_map){};
    ~DisplaySolutionComm(){};
    void execute(vector<string> params);
};

class ExitComm : public ICommand
{
    public:
    ExitComm(CacheMap *_map):ICommand(_map){};
    ~ExitComm(){};
    void execute(vector<string> params);
};
  