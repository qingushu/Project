#include <iostream>
#include <fstream>
#include "maze.h"


using namespace std;

int main(int argc, char **argv)
{
    // Commented out to facilitate testing.

    if (argc != 2) {
        std::cout << "USAGE: PathFinder <path>" << std::endl;
        return -1;
    }


    //bool test_maze[15][15] = {{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              //{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                              //{1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
                              //{1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
                              //{1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
                              //{1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1},
                              //{1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
                              //{1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1},
                              //{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1},
                              //{1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
                              //{1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1},
                              //{1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
                              //{1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
                              //{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                              //{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}};

    //Maze maze(test_maze, 15, 15);
    //maze.print();
    Maze maze(argv[1]);
    maze.print();
    maze.stackpath();
    maze.qpath();
    return 0;
}
