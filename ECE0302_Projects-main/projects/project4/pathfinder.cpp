//include statements
#include "lib/image.h"
//#include <image.h>
#include <iostream>
#include "deque.hpp"
#include <utility>
using namespace std;

void SolveMaze(pair<int, int> coor, Image<Pixel> maze)
{
 //reset the maze with the appropriate solution point
 //make the correct pixel green
  //Image<Pixel> maze = readFromFile(argv[1]);  //should yoink the first image
  maze(coor.first, coor.second) = GREEN;
}
//test to see if the suspected solution is a whitespace on the edge of the maze
bool isSolution(pair<int, int> coor, Image<Pixel> maze)
{
  //in order to be on any edge
  if(coor.first == maze.width()-1 || coor.first == 0 || coor.second == 0 || coor.second == maze.height() - 1)
  {
    //we also must have a white piece
    if(maze(coor.first, coor.second) == WHITE)
    {
      return true;
    }
    return false;
  }
  return false;
}

int main(int argc, char *argv[])
{

  //VARIABLES
  bool foundGoal = false;
  //flag to see if red is found -- starting point
  bool redFound = false;
  //flag to see if there are invalid colors
  bool inValColors = false;
  //frontier deque -- type pair int
  Deque<pair<int, int>> frontier;
  //generic coordinates
  pair<int, int> coordinate;

  //read in the picture of the maze
  Image<Pixel> maze = readFromFile(argv[1]);  //should yoink the first image
  //ARRAY TO HOLD MAP
  int explore[maze.width()][maze.height()] = {0};
  //testing if items is all zero
  {
  cout << "width: "  << maze.width() << endl;
  cout << "height: " << maze.height() << endl;
  int count = 0;
  for(int i = 0; i < maze.width(); i++)
  {
    for(int j = 0; j < maze.height(); j++)
    {
      if (explore[i][j] == 0)
      {
        count ++;
      }
    }
  }
  cout << "count: " << count << endl;
  }
  //AT THIS POINT -- we have a new array initalized to 0

  //need to check each pixel in search of the start -- red pixel
  //also need to make sure the maze only contains valid pixels
  for(int i = 0; i < maze.width(); i++)
  {
    for (int j = 0; j < maze.height(); j++)
    {
      //look at the pixel, see if it is red
      if(maze(i,j)== RED)
      {
        if(redFound == false)
        {
          redFound == true;
          //testing
          cout << "We have a red starting pixel" << endl;
          coordinate.first = i;
          coordinate.second = j;
          frontier.pushBack(coordinate);
        }
        else{
          //cant have more than one red
          cout << "ERROR! Cannot have more than one red pixel." << endl;
          exit(EXIT_FAILURE);
        }
        
      }
      if(maze(i,j) != RED && maze(i,j) != WHITE && maze(i,j) != BLACK )
      {
        //error
        cout << "ERROR! maze contains an incorrect color." << endl;
        exit(EXIT_FAILURE);
      }
    }
    
  }
  //a goal is any edge with a white space
  //pixel 0,0 is the top left
  //check left bounds -- maze(width,heigth)
  for(int i = 0; i < maze.height(); i++)
  {
    //increase height while x is 0
    if(maze(0,i) == WHITE)
    {
      foundGoal == true;
    }
  }
  
  //check right bounds -- maze(width,heigth)
  for(int i = 0; i < maze.height(); i++)
  {
    //increase height while x is 0
    if(maze(maze.width()-1,i) == WHITE)
    {
      foundGoal = true;
    }
  }
  
  //check top bounds -- maze(width,heigth)
  for(int i = 0; i < maze.width(); i++)
  {
    //increase height while x is 0
    if(maze(i,0) == WHITE)
    {
      foundGoal = true;
    }
  }

  //check bottom bounds -- maze(width,heigth)
  for(int i = 0; i < maze.width(); i++)
  {
    //increase height while x is 0
    if(maze(i,maze.height()-1) == WHITE)
    {
      foundGoal = true;
    }
  }

  //what if we did not find a goal?
  if(foundGoal == false)
  {
    cout << "Error: no goal was found. Impossible maze." << endl;
    exit(EXIT_FAILURE);
  }
  
  //push the coordinates of the start
  //check if the starting point is an edge (solution)
  {
    coordinate = frontier.front();
    if(isSolution(coordinate, maze))
    {
      SolveMaze(coordinate, maze);
      //exit succesfully
      exit(EXIT_SUCCESS);
    }
  }
  //breadth first function
  //while there is more to explore keep moving
  while(!frontier.isEmpty())
  {
    //pop the current state from the deque and put in the explored coordinates
    coordinate = frontier.front();
    frontier.popFront();
    explore[coordinate.first][coordinate.second] = 1;
  }
  //if we reach this point return a failure
  cout << "The program didn't find a solution" << endl;
  exit(EXIT_FAILURE);
}

