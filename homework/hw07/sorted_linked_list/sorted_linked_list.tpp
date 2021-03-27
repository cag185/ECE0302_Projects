#include "sorted_linked_list.hpp"
#include <stdexcept>

//DONE
template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{
}
//DONE
template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}
//DONE
template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(const SortedLinkedList<T>& x)
{
  LinkedList<T>::operator=(x);
  return *this;
}
//DONE
template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

//DONE
template <typename T>
bool SortedLinkedList<T>::isEmpty()
{
  return LinkedList<T>::isEmpty();
}
//DONE
template <typename T>
std::size_t SortedLinkedList<T>::getLength()
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  // want to insert an item in the sorted location
  //std::cout << "We are in insert" << std::endl;

  //if the size is zero
  if(getLength() == 0)
  {
    //test
    //std::cout << "We have inserted into an empty LL" << std::endl;
     LinkedList<T>::insert(0,item); //enters the item to the first position
     return;
  }
  else {
    //test
    //std::cout << "We are attempting to insert in a non-empty LL" << std::endl;
    for(int i  = 0; i < getLength(); i++)
    {
      //if we reach the value we are trying to insert
      if(getEntry(i) >= item)
      {
        //inserts at the position we found to be greater than or equal to the item
        //test
        //std::cout << "We have inserted in a non-empty LL" << std::endl;
        LinkedList<T>::insert(i, item);   
         return;
      }
    }
    
    //appending to the end
    if(getEntry(getLength()-1) < item)
    {
      //std::cout <<"we have appended to a non-empty LL" << std::endl;
      LinkedList<T>::insert(getLength()-1,item);
      return;
    }
  }
}

template <typename T> //Done
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  //loop until item we want to remove is found
  for (int i = 0; i < getLength(); i++)
  {
    if(getEntry(i) == item)
    {
      //remove
      LinkedList<T>::remove(i);
      return;
    }
  }
}

template <typename T> //Done
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  //remove
  LinkedList<T>::remove(position);
  return;
}

template <typename T> //DONE 
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T> //DONE
T SortedLinkedList<T>::getEntry(std::size_t position)
{
  return LinkedList<T>::getEntry(position); // was position + 1 before
}

template <typename T> //DONE
long int SortedLinkedList<T>::getPosition(const T& newValue)
{
  //get the value at 0 and see if it is null
  if(getLength() == 1)
  {
    return 0;
  }
  for(int i = 0; i < getLength(); i++)
  {
    if(getEntry(i) == newValue)
    {
      return i;
    }
  }
  return -1;
}
