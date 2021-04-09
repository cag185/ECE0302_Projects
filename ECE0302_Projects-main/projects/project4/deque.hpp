#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"
#include "Node.hpp"

template <typename T>
class Deque: public AbstractDeque<T>{

  //----------//PRIVATE//----------//
private:
//size variable
  std::size_t size;
  //pointer to the head
  Node<T> * head;

  //----------//PUBLIC//----------//
public:
  //---//ORIGINAL FUNCTIONS//---//

  //CONSTRUCTOR//
  Deque();

  //DESTRUCTOR//
  ~Deque();

  //COPY ASSIGNMENT//
  Deque& operator=(const Deque& x);

  //COPY CONSTRUCTOR//
  Deque(const Deque& x);

  //get the length
  std::size_t getLength();

  //---//TEMPLATE FUNCTIONS//---//

  //returns true if the deque is empty
  bool isEmpty() const noexcept;

  //add item to the front of the deque
  void pushFront(const T & item);

  //remove an item at the front of a deque
  void popFront();

  //returns the item at the front of the deque
  T front() const;

  //at item to the back of the deque
  void pushBack(const T & item);

  //remove an item at the back of the deque
  void popBack();

  //returns the item at the back of the deque
  T back() const;
};

#include "deque.tpp"

#endif
