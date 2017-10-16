#include<iostream>
#include<stack>
#include<queue>


class Position{
	 public:
        int i;     //row
	      int j;     //column
	       //1, 0, or 'X'

	// reference to the prev position (parent) that leads to this position on a path
	 Position *parent;

	 Position(int x, int y){
		i=x; j = y;
	 }

	 Position(int x, int y, Position *p){
		i=x; j = y;
		parent= p;
	 }
   Position(){}
};

class Cell {
public:
    int x, y;
    bool wall;
    bool visited1;
    bool visited2;
    Cell() {}
};

class Maze {
    int width;
    int height;
    Cell **cells;
    std::stack<Cell> cellStack;
    std::queue<Cell> cellQueue;


public:
    Maze(char *path)
    {
      std::ifstream fin;
      fin.open(path);
      fin >> width;
      height = width;

      cells = new Cell*[width];
      for(int i = 0; i < height; ++i)
          cells[i] = new Cell[width];
      for (int i = 0; i < width; i++) {
          for (int j = 0; j < height; j++) {
              Cell *cell = &cells[i][j];
              cell->x = i;
              cell->y = j;
              fin >> cell->wall;

          }

      }
    }


    // A constructor to facilitate testing.
    Maze(bool maze[][15], int size_x, int size_y)
    {
        width = size_x;
        height = size_y;

        cells = new Cell*[width];
        for(int i = 0; i < height; ++i)
            cells[i] = new Cell[width];

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                Cell *cell = &cells[i][j];
                cell->x = i;
                cell->y = j;
                cell->wall = maze[i][j];
            }
        }
    }

    // Print the maze to stdout.
    void print()
    {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (cells[i][j].wall) {
                    std::cout << "█";
                } else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    void stackpath()
    {
    Cell currentCell = cells[0][0];
    Cell cell1;
    cellStack.push(cells[0][0]);

    int x, y;

    do{
        x = currentCell.x;
        y = currentCell.y;


        cells[x][y].visited1 = true;


        if(x >= 0 && y-1 >= 0 && x < width && y-1 < height && !cells[x][y-1].wall && !cells[x][y-1].visited1){

               cellStack.push(cells[x][y-1]);
               cells[x][y-1].visited1 = true;
        }


       else if(x+1 >= 0 && y >= 0 &&  x+1 < width && y < height &&!cells[x+1][y].wall && !cells[x+1][y].visited1){
                    cellStack.push(cells[x+1][y]);
                    cells[x+1][y].visited1 = true;
        }


        else if(x >= 0 && y + 1 >= 0 &&  x < width && y+1 < height && !cells[x][y+1].wall && !cells[x][y+1].visited1){
                 cellStack.push(cells[x][y+1]);
                 cells[x][y+1].visited1 = true;
        }


       else if(x-1 >= 0 && y >= 0 &&  x-1 < width && y < height &&!cells[x-1][y].wall && !cells[x-1][y].visited1){
              cellStack.push(cells[x-1][y]);
              cells[x-1][y].visited1 = true;
       }

       else{

            cellStack.pop();
            if(cellStack.empty())
                std::cout << "There's no path.";
      }

        currentCell = cellStack.top();

      } while(currentCell.x!=width-1 || currentCell.y != height-1 );

      while(!cellStack.empty()){
          cell1 = cellStack.top();
          cellStack.pop();
          std::cout << "[" << cell1.x << "]" << "[" << cell1.y << "]" << ",  ";
      }
      std::cout << std::endl << std::endl;
  }

  void qpath()
  {
  Cell currentCell = cells[0][0];
  cellQueue.push(cells[0][0]);

  int x, y;

  do{
      x = currentCell.x;
      y = currentCell.y;
      cells[x][y].visited2 = true;



     if(x >= 0 && y-1 >= 0 && x < width && y-1 < height && !cells[x][y-1].wall && !cells[x][y-1].visited2){

              cellQueue.push(cells[x][y-1]);
              cells[x][y-1].visited2 = true;

      }

     if(x+1 >= 0 && y >= 0 &&  x+1 < width && y < height &&!cells[x+1][y].wall && !cells[x+1][y].visited2){
                cellQueue.push(cells[x+1][y]);
                cells[x+1][y].visited2 = true;

      }


     if(x >= 0 && y + 1 >= 0 &&  x < width && y+1 < height && !cells[x][y+1].wall && !cells[x][y+1].visited2){
              cellQueue.push(cells[x][y+1]);
              cells[x][y+1].visited2 = true;

      }

      if(x-1 >= 0 && y >= 0 &&  x-1 < width && y < height &&!cells[x-1][y].wall && !cells[x-1][y].visited2 ){
                cellQueue.push(cells[x-1][y]);
                cells[x-1][y].visited2 = true;
      }

      if(cellQueue.empty())
          std::cout << "There's no path.";
          cellQueue.pop();
          currentCell = cellQueue.front();
          std::cout << "[" << currentCell.x << "]" << "[" << currentCell.y << "]" << ",  ";

     }while(currentCell.x!=width-1 || currentCell.y != height-1 );



  /*      while(current.i != 0 || current.j != 0){

          std::cout << std::endl << std::endl;
          std::cout << "[" << current.i << "]" << "[" << current.j << "]" << ",  ";
          current = current->parent;
        }

*/

  }
};
