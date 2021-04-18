
#ifndef _HEAP_PRIORITY_QUEUE_H_
#define _HEAP_PRIORITY_QUEUE_H_

#include "abstract_priority_queue.h"
#include "dynamic_array_list.h"

template <typename T>
class HeapPriorityQueue: public AbstractPriorityQueue<T>    //MaxHeap
{
public:
    
    // return true if the priority queue is empty
    bool isEmpty();
    
    // insert item into the queue
    void add(const T& item);
    
    // remove highest priority item from the queue
    void remove();
    
    // get the item with the highest priority from the queue
    T peek();
    
private:
    
    DynamicArrayList<T> lst;
};

//DONE
template <typename T>
bool HeapPriorityQueue<T>::isEmpty()
{
    //toDo
    return(lst.isEmpty());
    
}

template <typename T>
void HeapPriorityQueue<T>::add(const T& item)
{
    //need to make sure that when we add a value, the Binary Tree is balanced
    //do this by inserting in the correct place
    
    //Case where we are inserting into an empty heap
    if(lst.isEmpty())
    {
        
        lst.insert(0, item);
        return;
    }

    //Case where we are adding to the middle of a heap or the beggining
        //always compare the inserted item to its parent
        //int to hold index of parent
        int startLoc = lst.getLength();
        int parentLoc = (startLoc-1)/2;
        bool correctLoc = false;
        //insert the value at the end of the array
        lst.insert(lst.getLength(), item);
        while(!correctLoc)
        {
            
            //compare the item to the value at the index of the parent
            if(item > lst.getEntry((parentLoc)))
            {
                //swap the items
                T swapItem = lst.getEntry(parentLoc);
                lst.setEntry(parentLoc, lst.getEntry(startLoc));
                lst.setEntry(startLoc, swapItem);
                //reset the values of start and parent for next iteration
                startLoc = parentLoc;
                parentLoc = (startLoc-1)/2;
            }
            else
            {
                //we have trickled up far enough
                correctLoc = true;
                return;
            }
        }


    
}

template <typename T>
void HeapPriorityQueue<T>::remove()
{
    std::cout << "in remove" << std::endl;
    //yoink the value at the end of the heap
    lst.setEntry(0, lst.getEntry(lst.getLength()-1));
    std::cout << "here" << std::endl;
    //remove the item at the end of the heap
    lst.remove(lst.getLength()-1);
    std::cout << "here" << std::endl;

    //need to check the children of the new root and see which is larger
    //if the child is larger than the root, swap em
    std::cout << "here" << std::endl;
    int newRoot = 0;
    int leftChild = newRoot * 2 + 1;
    std::cout << "we made it here" << std::endl;
    int rightChild = leftChild + 1;
    T swapItem;
    std::cout <<"we made it past intializing the children" << std::endl;
    bool complete = false;
    int count = 1;

    //if the tree is single node
    if(lst.getLength() == 1)
    {
        complete = true;
        return;
    }

    //two nodes
    if(lst.getLength() == 2)
    {
        if(lst.getEntry(0) < lst.getEntry(1))
        {
            //swap
            swapItem = lst.getEntry(1);
            lst.setEntry(1, lst.getEntry(0));
            lst.setEntry(0, swapItem);
            complete = true;
            return;
        }
    }

    //test left child and right child
    if(lst.getLength() >= 3)
    {
    while(!complete)
    {
        //keep testind swappin
        if(lst.getEntry(leftChild) > lst.getEntry(newRoot) && lst.getEntry(rightChild) < lst.getEntry(newRoot))
        {
            std::cout << "left child" << std::endl;
            //swap the values -- parent and left child
            swapItem = lst.getEntry(newRoot);
            lst.setEntry(newRoot, lst.getEntry(leftChild));
            lst.setEntry(leftChild, swapItem);
            //reset the root
            newRoot = leftChild;
            leftChild = newRoot * 2 + 1;
            rightChild = leftChild + 1;
            std::cout << "New Root: " << lst.getEntry(newRoot) << std::endl;
            std::cout << "Left Child: " << lst.getEntry(leftChild) << std::endl;
            std::cout << "Right Child: " << lst.getEntry(rightChild) << std::endl;

        }
        else if(lst.getEntry(rightChild) > lst.getEntry(newRoot) && lst.getEntry(leftChild) < lst.getEntry(newRoot))
        {
            std::cout << "right child" << std::endl;
            //swap the values -- parent and right child
            swapItem = lst.getEntry(newRoot);
            lst.setEntry(newRoot, lst.getEntry(rightChild));
            lst.setEntry(rightChild, swapItem);
            //reset the root
            newRoot = rightChild;
            leftChild = newRoot * 2 + 1;
            rightChild = leftChild + 1;
            std::cout << "New Root: " << lst.getEntry(newRoot) << std::endl;
            std::cout << "Left Child: " << lst.getEntry(leftChild) << std::endl;
            std::cout << "Right Child: " << lst.getEntry(rightChild) << std::endl;
        }
        //check to make sure the root is the greatest
        for(int i = 1; i < lst.getLength(); i++)
        {
            if(lst.getEntry(0) >lst.getEntry(i))
            {
                count++;
            }
        }
        //if the head is greater than all other values
        if(count == lst.getLength())
        {
            complete = true;
            return;
        }
    }    
    }

}

template <typename T>
T HeapPriorityQueue<T>::peek()
{
    //return the root
    return lst.getEntry(0);
}


#endif // _HEAP_PRIORITY_QUEUE_H_
