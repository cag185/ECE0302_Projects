#include "deque.hpp"

//main functions
//----------//PUBLIC//----------//

  //---//ORIGINAL FUNCTIONS//---//

  //CONSTRUCTOR//
  template<typename T>
  Deque<T>::Deque()
  {

  }

  //DESTRUCTOR//
  template<typename T>
  Deque<T>::~Deque()
  {

  }

  //COPY ASSIGNMENT//
  template<typename T>
  Deque<T>& Deque<T>::operator=(const Deque& x)
  {

  }

  //COPY CONSTRUCTOR//
  template<typename T>
  Deque<T>::Deque(const Deque& x)
  {

  }

  //---//TEMPLATE FUNCTIONS//---//

  //returns true if the deque is empty
  template<typename T>
  bool Deque<T>::isEmpty()
  {
    //return false as default
    return false;
  }

  //add item to the front of the deque
  template<typename T>
  void Deque<T>::pushFront(const T & item)
  {

  }

  //remove an item at the front of a deque
  template<typename T>
  void Deque<T>::popFront()
  {

  }

  //returns the item at the front of the deque
  template<typename T>
  T Deque<T>::front() const
  {
    //return t as defualt
    //return T;
  }

  //at item to the back of the deque
  template<typename T>
  void Deque<T>::pushBack(const T & item)
  {

  }

  //remove an item at the back of the deque
  template<typename T>
  void Deque<T>::popBack()
  {

  }

  //returns the item at the back of the deque
  template<typename T>
  T Deque<T>::back() const
  {
    //return t as defualt
    //return T;
  }