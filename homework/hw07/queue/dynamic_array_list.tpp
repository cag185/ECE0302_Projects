#include "dynamic_array_list.h"

#include <algorithm>
#include <stdexcept>

#include <iostream>

//done
template <typename T>
DynamicArrayList<T>::DynamicArrayList()
{
  //Need to initialize a queue -- create a DA array
  data = new T [0];   //creates array with size 1
  //usedSpace= 0; //tracks the used space
  size = 0;//tracks how much memory is allocated

}

//done?
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
    //To do -- never gets used by queue
}
    
//done
template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
  std::clog << "DynamicArrayList Destructor called." << std::endl;
  //run clear
  clear();
  //need to completely remove data
  delete [] data;
}

//done?
template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> &x)
{
  //set one queue equal to another
  //clear();
  std::cout << "size of x: " << x.getLength() << std::endl;
  for (std::size_t i = 0; i < x.getLength(); i++)
  {
    std::cout << "the data in the og: " << x.data[i] << std::endl;
  }
  return *this;
}

//done?
template <typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T>& y)
{
  //TODO
  //never has to actually swap
}

//done
template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
  //if size = 0
  return (size == 0);
}

template <typename T> // done
std::size_t DynamicArrayList<T>::getLength()
{
  //return the size
  //std::cout << "size: " << size <<std::endl;
  return size;
}

template <typename T> //maybe done
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
  if(position == getLength())
  {
    //should always be here
    //if the queue is full resize
    T* newPoint = new T [size+1];
    for(std::size_t i = 0; i < size; i++)
    {
      newPoint[i] = data[i];
    }
    delete [] data;
    T * data = newPoint;
    size++;
  }
  data[position] = item;
  std::cout << "The item being inserted: " << data[position] << std::endl;
  
  for(int i = 0; i < size; i++)
  {
    std::cout << "items:  " << data[i] << std::endl;
  }
  //std::cout << "item at 1: " << data[0] << std::endl;
 // std::cout << "item at 2: " << data[1] << std::endl;
  std::cout << "item at 3: " << data[2] << std::endl;
}

//done maybe
template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
  /*/std:: cout << "current size = " << size << std::endl;
  //diff implementation
  for(std::size_t i = 0; i < getLength()-1; i++)
  {
    //data[i] = data[i];
    std::cout<< "since dequing, data[i] = " << getEntry(i) << std::endl;
  }
  size--; */
  //should only have to remove at the beggining
  if (position == 0)
  {
    //need to create a new DDA and copy everything after the first index
    T * temp = new T [size-1];
    for(int i = 1; i <size; i++)
    {
      std::cout << "values of data: " << data[i] << std::endl;
    }
    for(std::size_t i  = 1; i < size; i++)
    {
      //copy values
      temp[i-1] = data[i]; //offset to account for index 1
      //std::cout << " temp[i]: " << temp[i] << std::endl;
      
    }
    std::cout << "data at the last index: " << data[-1] << std::endl;
    std::cout << "data at the last index: " << data[0] << std::endl;
    std::cout << "data at the last index: " << data[1] << std::endl;
    std::cout << "data at the last index: " << data[2] << std::endl;
    //delete data, remake it, delete temp
    delete [] data;
    T * data = temp;
    //delete [] temp;
    //std::cout << "item at 0 after removal" << data[0]<<std::endl;
    size--;

    for (int i = 0; i < getLength(); i++)
    {
     // std::cout << " Temp[i]: " << temp[i] << std::endl;
    }
  } 
}

//done
template <typename T>
void DynamicArrayList<T>::clear()
{
  //delete the pointer, resize size
  size = 0;
  delete [] data;
  //reinitialize data array in case we want to clear and have data array in existence
  T * data = new T [1];
}

//done
template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
  //should only have to get entry at 0
  //if(position == 0)
  //{
  //  return data[0];
  //}
  //else 
  {
    std::cout << "This is the entry at pos checked: " << data[position] << std::endl;
    return data[position];
  }
  return T();
}

//done?
template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
  //never actually had to do this for a queue 
}
