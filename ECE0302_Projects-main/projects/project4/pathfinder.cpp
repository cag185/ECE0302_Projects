//include statements
#include "lib/image.h"
//#include <image.h>
#include <iostream>
//#include "deque.tpp"

using namespace std;

int main(int argc, char *argv[])
{

  //VARIABLES
  //array to hold goal
  int goal[1][2] = {0,0}; // width by height
  bool foundGoal = false;
  //flag to see if red is found -- starting point
  bool redFound = false;
  //flag to see if there are invalid colors
  bool inValColors = false;
  
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
      //goal = these coordinates
      goal[1][1] = 0;
      goal[1][2] = i;
      foundGoal == true;
    }
  }
  
  //check right bounds -- maze(width,heigth)
  for(int i = 0; i < maze.height(); i++)
  {
    //increase height while x is 0
    if(maze(maze.width()-1,i) == WHITE)
    {
      //goal = these coordinates
      goal[1][1] = maze.width()-1;
      goal[1][2] = i;
      foundGoal = true;
    }
  }
  
  //check top bounds -- maze(width,heigth)
  for(int i = 0; i < maze.width(); i++)
  {
    //increase height while x is 0
    if(maze(i,0) == WHITE)
    {
      //goal = these coordinates
      goal[1][1] = i;
      goal[1][2] = 0;
      foundGoal = true;
    }
  }

  //check bottom bounds -- maze(width,heigth)
  for(int i = 0; i < maze.width(); i++)
  {
    //increase height while x is 0
    if(maze(i,maze.height()-1) == WHITE)
    {
      //goal = these coordinates
      goal[1][1] = i;
      goal[1][2] = maze.height()-1;
      foundGoal = true;
    }
  }

  //what if we did not find a goal?
  if(foundGoal == false)
  {
    cout << "Error: no goal was found. Impossible maze." << endl;
    exit(EXIT_FAILURE);
  }
  
}
