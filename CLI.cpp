#include "CLI.h"

using namespace std;

void CLI::chooseComms()
{
    string input;
    out << "Welcome to our maze game." << endl;
    out << "Please choose the commands you would like to have by typing the word in () and presing ENTER" << endl;
    out << "When you have finished adding commands, press 0." << endl;
    out << "The actions available are:" << endl;
    out << "   dir <path>                                                   (dir)" << endl;                                      
    out << "   generate maze <name> <size> <my OR simple>                   (generate)" << endl;       
    out << "   display <name>                                               (display)" << endl;                                   
    out << "   save maze <name> <file name>                                 (save)" << endl;                     
    out << "   load maze <file name> <name>                                 (load)" << endl;                     
    out << "   maze size <name>                                             (maze)" << endl;                                 
    out << "   file size <file name>                                        (file)" << endl;                            
    out << "   solve <name> <bfs OR astar> <(IF astar:) manhattan OR arial> (solve)" << endl; 
    out << "   display solution <name>                                      (solution)" << endl;                          
    out << "   exit                                                         (exit)" << endl;  

    while(1)
    {
        getline(in, input, '\n');
        if( input == "0")
            break;
        invoker->add(input);     
    }
}


void CLI::start() 
{
    string input, name, size, alg, filename, heuristic;

    out << "Enter your command lines" << endl;

    vector<string> params;
    while (1)
    {
        params.clear();
        getline(in, input, '\n');
        char *n = new char[input.length() + 1];
        strcpy(n, input.c_str());
        string str = strtok(n, " ");

        if (str == "exit")
        {
            params.insert(params.end(), input);                         // exit
            invoker->execute(params);
        }
        else if (str == "dir")
        {
            params.insert(params.end(), str);                           // dir

            str = strtok(NULL, " ");
            params.insert(params.end(), str);                           // name

            invoker->execute(params);
        }
        else if (str == "generate")
        {
            params.insert(params.end(), str);                           // generate
            
            str = strtok(NULL, " ");
            params.insert(params.end(), str);                           // name

            str = strtok(NULL, " ");
            params.insert(params.end(), str);                           // size

            str = strtok(NULL, " ");
            params.insert(params.end(), str);                           // alg

            invoker->execute(params);
        }
        else if (str == "display")
        {
            params.insert(params.end(), str);                           // display

            str = strtok(NULL, " "); 
            params.insert(params.end(), str);                           // name OR solution

            if (str == "solution")
            {   
                params.erase(params.begin());

                str = strtok(NULL, " ");
                params.insert(params.end(), str);                       // name

                invoker->execute(params);
            }
            else
                invoker->execute(params);
        }
        else if (str == "save")
        {
            params.insert(params.end(), str);                           // save

            str = strtok(NULL, " ");                                    // maze

            str = strtok(NULL, " ");
            params.insert(params.end(), str);                           // name

            str = strtok(NULL, " ");
            params.insert(params.end(), str);                           // filename
           
            invoker->execute(params);
        }
        else if (str == "load")
        {
            params.insert(params.end(), str);                           // load

            str = strtok(NULL, " ");                                    // maze

            str = strtok(NULL, " ");
            params.insert(params.end(), str);                           // filename

            str = strtok(NULL, " ");
            params.insert(params.end(), str);                           // name
            
            invoker->execute(params);
        }
        else if (str == "maze")
        {
            params.insert(params.end(), str);                           // maze

            str = strtok(NULL, " ");
            params.insert(params.end(), str);                           // size

            str = strtok(NULL, " ");
            params.insert(params.end(), str);                           // name
        
           invoker->execute(params);
        }
        else if (str == "file")
        {
            params.insert(params.end(), str);                           // file
            
            str = strtok(NULL, " ");
            params.insert(params.end(), str);                           // size

            str = strtok(NULL, " ");
            params.insert(params.end(), str);                           // name
        
           invoker->execute(params);
        }
        else if (str == "solve")
        {
            params.insert(params.end(), str);                           // solve
            
            str = strtok(NULL, " ");
            params.insert(params.end(), str);                           // name
            
            str = strtok(NULL, " ");
            params.insert(params.end(), str);                           // alg
            
            if(str == "astar")
            {
                str = strtok(NULL, " ");                                // heuristic
                params.insert(params.end(), str);
            }
            invoker->execute(params);
        }
        params.clear();
        delete[] n;
    }
}