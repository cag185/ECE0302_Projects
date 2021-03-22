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
Stack<ItemType>::Stack() : headPtr(nullptr);
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
	if(headPtr == nullptr)
	{
		return true
	}
	else{
		return true;
	}
}  // end isEmpty

// Size method -- Done
template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size

// push method 
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	//increase the current size variable
	currentSize++;
	return true;
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const
{
	ItemType returnItem;
	return returnItem;
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	return false;
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
}  // end clear

