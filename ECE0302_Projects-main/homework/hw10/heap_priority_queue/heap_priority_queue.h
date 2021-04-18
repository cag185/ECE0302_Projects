
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
        lst.setEntry(0, item);
        return;
    }
    //Case where we insert into Array[0] when the heap is not empty
    //check item w every item in the array
        bool isLargest = false;
        int big = 0;
        for(int i = 0; i < lst.getLength(); i++)
        {
            if(item > lst.getEntry(i))
            {
                big++;
            }
        }
        if(big == lst.getLength())
        {
            //item is the largest item and should become the new head
            for(int b = 0; b < lst.getLength(); b++)
            {
                lst.setEntry(b+1, lst.getEntry(b));
            }
            //set item to head
            lst.setEntry(0,item);
        }
    //Case where we are adding to the middle of a heap

    
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
