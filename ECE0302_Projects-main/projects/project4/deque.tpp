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

    //increase size
    size++;
  }

  //remove an item at the front of a deque  --//done
  template<typename T>
  void Deque<T>::popFront()
  {
    //if empty throw error
    if(isEmpty())
    {
      throw std::runtime_error("Cant pop if the list is empty");
    }
    //want to remove the head
    //create a temp ptr to head
    Node<T> *newHead = head;
    newHead = newHead->getNext();
    //remove the old head
    free(head);
    head = newHead;
    //decrease size
    size--;

  }

  //returns the item at the front of the deque --//done
  template<typename T>
  T Deque<T>::front() const
  {
    //throw exception if the list is empty
    if(isEmpty())
    {
      throw std::runtime_error("cant return front while Deque is empty");
    }
    //return t as defualt
    return head->getItem();
  }

  //at item to the back of the deque  --//done
  template<typename T>
  void Deque<T>::pushBack(const T & item)
  {
    //create a tempPointer
    Node<T> * newNode = head;
    //if empty, push the value to the head positon
    //need to add a new node before the nullptr
    if(isEmpty())
    {
      //std::cout << "should see this once" << std::endl;
      Node<T> * newHead = new Node<T>;
      newHead->setItem(item);
      newHead->setNext(newNode);
      head = newHead;
      size++;
      return;
    }
    while(newNode->getNext() !=nullptr)
    {
      newNode = newNode->getNext();
      //std::cout << "count" << std::endl;
    }
    
    //std::cout << "item: " << newNode->getItem() << std::endl;
    
    //create a new node pointer to add value
    Node<T> * insertNode = new Node<T>;    
    //std::cout << "Here" << std::endl;
    insertNode->setItem(item);
    //std::cout << "Here" << std::endl;
    newNode->setNext(insertNode);
   // std::cout << "Here" << std::endl;
    insertNode->setNext(nullptr);
    //std::cout << "Here" << std::endl;
    //at end of list, add node
    
    //increase size
    size++;
  }

  //remove an item at the back of the deque --//done
  template<typename T>
  void Deque<T>::popBack()
  {
    //make sure the deque isnt empty
    if(isEmpty())
    {
      throw std::runtime_error("cant pop the back if the deque is empty");
    }
    //remove an item at the end of queue
    //create a temp pointer
    Node<T> *newNode = head;
    int i = 1;
    while(i < size-1)
    {
      newNode = newNode->getNext();
      i++;
    }
    //at the end of linked list
    newNode->setNext(nullptr);
    //decrease size
    size--;
  }

  //returns the item at the back of the deque --//done
  template<typename T>
  T Deque<T>::back()const
  {
    //check if empty
    if(isEmpty())
    {
      //throw error
      throw std::runtime_error("cant return the back if deque is empty");
    }
    //create pointer to head
    Node<T> * newPtr = head;
    while(newPtr->getNext()!= nullptr)
    {
      newPtr = newPtr->getNext();
    }    
    //return the item at the end
    return newPtr->getItem();
  } 