
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
        std::cout <<"here" << std::endl;
        lst.insert(0, item);
        std::cout << "worked" << std::endl;
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
                return;
            }
        }


    
}

template <typename T>
void HeapPriorityQueue<T>::remove()
{
    //todo
}

template <typename T>
T HeapPriorityQueue<T>::peek()
{
    //return the root
    return lst.getEntry(0);
}


#endif // _HEAP_PRIORITY_QUEUE_H_
