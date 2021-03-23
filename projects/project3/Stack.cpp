//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

//DEFAULT CONSTRUCTOR
// use the shortcut to make the head assign to the null pointer - done
template<class ItemType>
Stack<ItemType>::Stack() : headPtr(nullptr)
{
}  // end default constructor

// DESTRUCTOR -- done
template<class ItemType>
Stack<ItemType>::~Stack()
{
	//pop the stack until it is empty
	while (!isEmpty())
		pop();
}  // end destructor

// isEmpty method -- Done
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	return headPtr == nullptr;
}  // end isEmpty

// Size method -- Done
template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size

// push method -- Done
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	//need to add a value via a node
	Node<ItemType> * newNodePtr = new Node <ItemType> (newItem, headPtr);
	headPtr = newNodePtr;
	newNodePtr = nullptr;

	//increase the current size variable
	currentSize++;
	return true;
}  // end push

//	peek method -- done
template<class ItemType>
ItemType Stack<ItemType>::peek() const
{

	//make sure that the stack is not empty
	//assert(!isEmpty());
	//int i = 0;
	//Node<ItemType> * tempNode = new Node <ItemType>;
	//tempNode = headPtr;
	//while (i <= currentSize )
	//{
	//	tempNode = tempNode->getNext();	//get the next node
	//}
	//ItemType returnItem;
	//ItemType returnItem = tempNode->getItem();
	//delete the pointer
	//delete tempNode;
	//return returnItem;
	if (!isEmpty())
	{
		return headPtr->getItem();
	}
	//return;
	
}  // end peek

// pop method -- DONE
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	bool result = false;
	if(!isEmpty())
	{
		//the stack is not empty so return the top
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();

		//return the deleted node
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		result = true;

		//reduce size
		currentSize--;
	}
	return result;
}  // end pop

// clear method DONE
template<class ItemType>
void Stack<ItemType>::clear()
{
	//create a pointer to the head
	Node<ItemType> * NodePtr = headPtr;

	//loop until the next pointer is NULL
	while (NodePtr != NULL)
	{
		//assign to head
		NodePtr = headPtr;	
		//move one more
		NodePtr = NodePtr->getNext();
		//delete the head
		delete headPtr;
		//reassign the head
		headPtr = NodePtr;
	}
	currentSize = 0;
}  // end clear

