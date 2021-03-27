#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(const SortedLinkedList<T>& x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty()
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength()
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  // want to insert an item in the sorted location
  std::cout << "We are in insert" << std::endl;

  //if the size is zero
  if(getLength() == 0)
  {
    //test
    std::cout << "We have inserted into an empty LL" << std::endl;
     LinkedList<T>::insert(0,item); //enters the item to the first position
     return;
  }
  for(int i  = 0; i < getLength(); i++)
  {
    //if we reach the value we are trying to insert
    if(getEntry(i) >= item)
    {
      //inserts at the position we found to be greater than or equal to the item
      //test
      std::cout << "We have inserted in a non-empty LL" << std::endl;
       LinkedList<T>::insert(i, item);  
       return;
    }

  }
  //increment size
  listLength++;

}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  // todo
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  // todo
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position)
{
   LinkedList<T>::getEntry(position); // was position + 1 before
}

template <typename T>
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
}
