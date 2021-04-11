//include statements
#include "lib/image.h"
#include <image.h>
#include <iostream>
//#include "deque.tpp"

using namespace std;

int main(int argc, char *argv[])
{
  //read in the picture of the maze
  Image<Pixel> maze = readFromFile(argv[1]);  //should yoink the first image
  //if the intial red pixel is the goal, replace the red pixel with a green one

}
