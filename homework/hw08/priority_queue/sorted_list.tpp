#include "sorted_list.h"

template <typename T, typename L>
SortedList<T, L>::SortedList()
{
  // nothing to do, plist gets created on the stack
}

template <typename T, typename L>
SortedList<T, L>::SortedList(const SortedList<T, L> & x)
{
  plist = x.plist; // use copy assignment to implement copy construction
}

template <typename T, typename L>
SortedList<T, L>& SortedList<T, L>::operator=(const SortedList<T, L>& x)
{
  plist = x.plist;
  return *this;
}

template <typename T, typename L>
SortedList<T, L>::~SortedList()
{
  // plist destructor gets called automatically
}

template <typename T, typename L>
bool SortedList<T, L>::isEmpty()
{
  return plist.isEmpty();
}

template <typename T, typename L>
std::size_t SortedList<T, L>::getLength()
{
  return plist.getLength();
}

//done
template <typename T, typename L>
void SortedList<T, L>::insert(const T& item)
{
  // NEED TO ENSURE THAT ITEMS GET INSERTED FARTHER BACK DEPENDING ON THEIR VALUE
  for(std::size_t i = 0; i < plist.getLength(); i++)
  {
    //need to check to see if the value of item is less than the index of the array
    if(item <= plist.getEntry(i))
    {
      //move everything down by one, insert the item

      //insert 
      plist.insert(i, item);
    }
  }
}

//done?
template <typename T, typename L>
void SortedList<T, L>::remove(const T& item)
{
  //search for the item, remove it
  //shift everything back by one
  std::size_t grabber = 0;
  grabber = getPosition(item);
  //remove the item at the location
  plist.remove(grabber);  //automatically yoinks the data back by one index

}

template <typename T, typename L>
void SortedList<T, L>::removeAt(std::size_t position)
{
  plist.remove(position);
}

template <typename T, typename L>
void SortedList<T, L>::clear()
{
  plist.clear();
}

template <typename T, typename L>
T SortedList<T, L>::getEntry(std::size_t position)
{
  return plist.getEntry(position);
}

template <typename T, typename L> //DONE
long int SortedList<T, L>::getPosition(const T& newValue)
{
  //return the position of the first item at that value
  //traverse the array and when we find the item, record postion
  for(std::size_t i = 0; i < plist.getLength(); i++)
  {
    //loop until we find the value
    if(newValue == plist.getEntry(i))
    {
      return i;
    }
  }
  //return 255 if the array doesnt contain
  return 255;
}
