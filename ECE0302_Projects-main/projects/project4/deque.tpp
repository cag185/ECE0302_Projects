#include "deque.hpp"

//main functions
//need to use a linked list as storage
//----------//PUBLIC//----------//

  //---//ORIGINAL FUNCTIONS//---//

  //CONSTRUCTOR//
  template<typename T>
  Deque<T>::Deque():AbstractDeque<T>()
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
    //loop through the elements
    this = Deque(x);
    return *this;
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
    //set the size
    size = x.size;
  }

  //---//TEMPLATE FUNCTIONS//---//

  //get the length
  template<typename T>
  std::size_t Deque<T>::getLength()
  {
    return size;
  }

  //returns true if the deque is empty  --//done
  template<typename T>
  bool Deque<T>::isEmpty() const noexcept
  {
    return(size==0);
    //return false as default
    //return false;
  }

  //add item to the front of the deque  --//done
  template<typename T>
  void Deque<T>::pushFront(const T & item)
  {
    //create a new node and attatch it to the beginning
    Node<T> * newHead = new Node<T>;
    newHead->setItem(item);

    //create a new pointer to the head
    Node<T> *ptr = head;
    //asssign the newhead to be before the old one
    newHead->setNext(ptr);
    //reassign
    head = newHead;
  }

  //remove an item at the front of a deque  --//done
  template<typename T>
  void Deque<T>::popFront()
  {
    //want to remove the head
    //create a temp ptr to head
    Node<T> *newHead = head;
    newHead = newHead->getNext();
    //remove the old head
    free(head);
    head = newHead;

  }

  //returns the item at the front of the deque --//done
  template<typename T>
  T Deque<T>::front() const
  {
    //return t as defualt
    return head->getItem();
  }

  //at item to the back of the deque  --//done
  template<typename T>
  void Deque<T>::pushBack(const T & item)
  {
    //create a tempPointer
    Node<T> * newNode = head;
    while(newNode!=nullptr)
    {
      newNode = newNode->getNext();
    }
    //at end of list, add node
    Node<T> * endNode = new Node<T>;
    newNode->setNext(endNode);
    endNode->setItem(item);
    endNode->setNext(nullptr); 
  }

  //remove an item at the back of the deque --//done
  template<typename T>
  void Deque<T>::popBack()
  {
    //remove an item at the end of queue
    //create a temp pointer
    Node<T> *newNode = head;
    while(newNode!= nullptr)
    {
      newNode = newNode->getNext();
    }
    //at the end of linked list
    free(newNode);
    //might be redundant
    newNode = head;
    while(newNode!=nullptr)
    {
      newNode = newNode->getNext();
    }
    newNode->setNext(nullptr);
  }

  //returns the item at the back of the deque --//done
  template<typename T>
  T Deque<T>::back()const
  {
    //create pointer to head
    Node<T> * newPtr = head;
    while(newPtr!= nullptr)
    {
      newPtr = newPtr->getNext();
    }    
    //return the item at the end
    return newPtr->getItem();
  } 