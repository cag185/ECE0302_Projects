#include "dynamic_array_list.h"

#include <algorithm>
#include <stdexcept>

#include <iostream>

template <typename T>
DynamicArrayList<T>::DynamicArrayList()
{
  //Need to initialize a queue -- create a DA array
  data = new T [1];   //creates array with size 1
  usedSpace= 0; //tracks the used space
  size = 0;//tracks how much memory is allocated

}
  
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
    //TODO
}
    
template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
  std::clog << "DynamicArrayList Destructor called." << std::endl;
  //TODO
}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
  //TODO
  return *this;
}

template <typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T>& y)
{
  //TODO
}

template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
  //TODO
  return false;
}

template <typename T> // done
std::size_t DynamicArrayList<T>::getLength()
{
  //return the size
  return size;
}

template <typename T> //maybe done
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
  //want to insert an item, will be inserted at the end of the queue
  if(position == getLength())
  {
    //should always be here
    //if the queue is full, resize
    if(usedSpace <= getLength())
    {
     // std::size_t num = data->getLength() + 1;
      T * newPoint  = new T [size+1]; //make a slightly larger array
      for(std::size_t i = 0; i < size; i++)
      {
        newPoint[i] = data[i];
      }
      //delete the old point
      delete [] data;
      //recreate arrPoint
      T * data = newPoint;
      //delete the new pointer
      delete [] newPoint;
      size++;
    }

    //actually insert
    data[position] = item;
  }
}

template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
  //TODO
}

template <typename T>
void DynamicArrayList<T>::clear()
{
  //TODO
}

template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
  //TODO
  return T();
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
}
