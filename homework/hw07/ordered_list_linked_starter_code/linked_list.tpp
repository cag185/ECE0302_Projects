//change the implementation to start at index 0
#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  //initialize head pointer
  head = NULL;

  //initialize length variable
  listLength = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  //free all memory allocated
  //delete newNodePtr, 
  clear();
}

//copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  //incrementing variable
  std::size_t i = 0;
  //set head to temp pointer
  Node<T>* newNodePtr;// = new Node<T>;
  newNodePtr = x.head;
  //make size = 0
  listLength = 0;
  //loop through all elements -- copy
  while(i <= x.getLength())
  {
    this->insert(i, x.getEntry(i)); //snag value at i from x and set it to the node
    newNodePtr = newNodePtr->getNext();
    //increment
    i++;
  }
}

//swap values
template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  //swap head pointers
  Node<T>* head1;
  head1  = x.head;
  std::size_t tempSize = x.listLength;
  
  //swap
  x.head = y.head;
  y.head = head1;
  //swap sizes
  x.listLength = y.listLength;
  y.listLength = tempSize;
}

//copy assignment
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  //incrementing variable
  std::size_t i = 0;
  //set head to temp pointer
  Node<T>* newNodePtr;
  newNodePtr = x.head;
  //make size = 0
  listLength = 0;
  //loop through all elements -- copy
  while(i <= x.getLength())
  {
    this->insert(i, x.getEntry(i)); //snag value at i from x and set it to the node
    newNodePtr = newNodePtr->getNext();
    //increment
    i++;
  }
  return *this;
}

//check to see if the list is empty
template <typename T>
bool LinkedList<T>::isEmpty() const
{
  //check if the head pointer is null
  if(head == NULL)
  {
    return true;
  }
  return false;
}

//return the length of the list
template <typename T>
std::size_t LinkedList<T>::getLength() const
{
  //listLength
  return listLength;
}

//insert a value and shift list
template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  ///Cases for insertion
    //1. insert at the beginning (index 0)
    //2. insert in the middle
    //3. insert at the end

    //create a temp node
    Node <T>* newNodePtr;// = new Node<T>;

    //case 1
    if(position == 0)
    {
      newNodePtr = new Node <T>;
      //set value
      newNodePtr->setItem(item);
      //set next
      newNodePtr->setNext(head);
      //replace head with newNodePtr so that the pointer is the start and the head becomes the tail, which is null
      head = newNodePtr;
      //increase size
      listLength++;
      //return
      return true;
    }

    //case 2
    if(position > 0 && position < listLength)
    {
      //set newpointer = to head
      newNodePtr = head;
      //create a second node and placeholder node
      Node <T>* placeholder; //= new Node<T>;
      Node <T>* newNode2 = new Node<T>;
      //loop until postion
      for(std::size_t i = 0; i<position-1; i++)
      {
        newNodePtr = newNodePtr->getNext(); // follow the list until pos
      }
      placeholder = newNodePtr->getNext(); //assign placeholder to hold the OG position value
      newNode2->setItem(item); //set the new nodes data
      newNodePtr->setNext(newNode2); //set the new position to be newNode2
      newNode2->setNext(placeholder); // put new node before placeholder, dropping it after newNodePtr but before placeholder
      //increase length
      listLength++;
      //return
      return true;
    }
    //case 3
    if(position == listLength+1)
    {
      //create a second node
      Node <T>* newNode2 = new Node<T>;
      //assign pointer to head
      newNodePtr = head;
      for(std::size_t i = 0; i <listLength; i++)
      {
          //copy all values
          newNodePtr = newNodePtr->getNext();
      }
      //now newNodePtr = the last item in the list
      //assign value to new node
      newNode2->setItem(item);
      //set new node to be the next node
      newNodePtr->setNext(newNode2);
      //increase size
      listLength++;
      //return
      return true;
    }
  return false;
}

//remove a value and shift list
template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //There will be three cases
    //1. remove the item from the beggining
    //2. remove item from middle
    //3. remove item from the end

  //create a temp node
    Node <T>* newNodePtr; //= new Node<T>;
    Node <T>* newNode;// = new Node<T>;
    Node <T>* placeholder;// = new Node<T>;
  //1.
  if(position == 0)
  {
    //snag the next item in line
    newNodePtr = head->getNext();
    delete head;
    //remove head
    head = newNodePtr;
    //decrease size
    listLength--;
    delete newNodePtr;
    //delete newNode;
    //delete placeholder;
    //return
    return true;
  }

  //2. in the middle
  if(position > 0 && position < listLength)
  {
    //start at head
    newNodePtr = head;
    //follow the linked list until position
    for(std::size_t i = 0; i < position-1; i++)
    {
      newNodePtr = newNodePtr->getNext();
    }
    //node should be at position-1 
    //need placeholder to hold value that will be removed
    placeholder = newNodePtr->getNext(); // placeholder is node to be removed
    newNode = placeholder->getNext(); //new node is node after place holder
    //assign pointers to skip placeholder
    newNodePtr->setNext(newNode);

    //reduce size
    listLength--;
    //delete placeholder
    delete placeholder;
    //return
    return true;
  }

  //case 3 at the end
  if(position== listLength)
  {
    //loop until before the last item and make the next null
    newNodePtr = head;  //assign to head
    for(std::size_t a = 0; a <position-1; a++)
    {
      newNodePtr = newNodePtr->getNext(); // follow list till before position
    }
    placeholder = newNodePtr->getNext();
    newNodePtr->setNext(NULL); //make node at position = null

    //reduce size
    listLength--;
    //return
    delete placeholder;
    return true;
  }

  return false;
}

//clear all data from the list
template <typename T>
void LinkedList<T>::clear()
{
  //remove all values
  //set temp pointer to head

  Node<T> *newNodePtr = head;
  Node<T> *next = NULL;
  while(newNodePtr != NULL) // loop through every node and free it
  {
    next = newNodePtr->getNext();
    free(newNodePtr);
    newNodePtr = next;
  }
  head = NULL; //free head
  listLength = 0; //reset size
}

//get a specific entry -- works
template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //create temp pointer
  Node<T>* newNodePointer;// = new Node<T>;
  newNodePointer = head;
  //create a loop that starts at head and for Position times, returns the value of data
  for(std::size_t i = 0; i < position; i++ )
  {
    newNodePointer = newNodePointer->getNext();
  }
  //return the value at index postion
  return newNodePointer->getItem();
}

//set a specific position to a value
template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  //create a temp node
  Node<T>* newNodePtr;// = new Node<T>;
  newNodePtr = head; // set at the beggining
  //loop for position
  for(std::size_t i = 0; i <=position-1; i++)
  {
   newNodePtr = newNodePtr->getNext(); // advances through list 
  }
  //node should be at correct value
  //change
  newNodePtr->setItem(newValue);
}

