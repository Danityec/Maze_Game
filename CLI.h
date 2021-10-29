#pragma once
#include <iostream>
#include "Invoker.h"

using namespace std;

class CLI
{ 
public: 
    CLI(ostream &_out, istream &_in): in(_in), out(_out) {  srand(time(NULL)); invoker = new Invoker;};
    ~CLI() { delete invoker; };
    void start();
    void chooseComms();
private:
    ostream &out;
    istream &in;
    Invoker *invoker;
};
