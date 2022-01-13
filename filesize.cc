#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// output format to use IDENTICALLY:
//BSH:Saru> ./filesize input.3lines input.1line 
//program: ./filesize
// input.3lines: 3
// input.1line: 1
//
int main( int argc, char* argv[] )
{
    std::cout << "program: " << argv[0] << '\n';
    ifstream fin;
    int line_count = 0;
    string throwaway;

    // just to get you started, this is how to refer to the arguments that were passed
    for (int arg = 1; arg < argc; ++arg) {
        //check if file exist, if it doesn't say it has -1 lines
        fin.open(argv[arg]);
        if (fin)    //file exists
        {
            while (getline(fin, throwaway))
            {
                line_count++;
            }
            std::cout << " " << argv[arg] << ": " << line_count << '\n';
        }
        else {  //file doesn't exist
            std::cout << " " << argv[arg] << ": -1\n";
        }
        fin.close();
        line_count = 0;
    }

    exit(0); // this means that the program executed correctly!
}