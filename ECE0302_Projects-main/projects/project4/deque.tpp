#include "deque.hpp"

//main functions
//need to use a linked list as storage
//----------//PUBLIC//----------//

  //---//ORIGINAL FUNCTIONS//---//

  //CONSTRUCTOR//
  template<typename T>
  Deque<T>::Deque()
  {
    //reset size to 0
    size = 0;
    //initialize head to null
    head = nullptr;
  }

  //DESTRUCTOR//
  template<typename T>
  Deque<T>::~Deque()
  {
    //loop through the nodes and delete/ free
    Node<T> * newNode = head;
    Node<T> * deleteNode = NULL;
    while(newNode!= nullptr)
    {
      deleteNode = newNode->getNext();
      free(newNode);
      newNode = deleteNode;
    }
    //reset size
    head = nullptr;
    size = 0;
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
    //loop from the first element to the last and copy
    Node<T> * Point = x.head;
    for(std::size_t i = 0; i < x.getLength(); i++)
    {
      this->setItem(Point);
      Point = Point->getNext();
    }

  }

  //---//TEMPLATE FUNCTIONS//---//

  //get the length
  template<typename T>
  std::size_t Deque<T>::getLength()
  {
    return size;
  }

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