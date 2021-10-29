#include "CLI.h"
#include "TestMazeGenerator.h"
#include "Demo.h"
#include <stdio.h>

using namespace std;

int main()
{
    CLI cli(cout, cin);
    cli.chooseComms();
    cli.start();

    // int size = 30;
    
    // TestMazeGenerator test;

    // My2DMazeGenerator mmg;
    // test.testMazeGenerator(mmg, size);
    // Simple2DMazeGenerator smg;
    // test.testMazeGenerator(smg, size);

    // Demo demo;
    // demo.run(size);
    
    return 0;
}