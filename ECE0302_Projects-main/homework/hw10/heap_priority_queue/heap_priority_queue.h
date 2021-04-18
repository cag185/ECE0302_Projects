
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
    //toDo
    //need to make sure that when we add a value, the Binary Tree is balanced
    //do this by inserting in the correct place
    

    //Case where we are inserting into an empty heap
    if(lst.isEmpty())
    {
        lst.setEntry(0, item);
        return;
    }
    //Case where we insert into Array[0] when the heap is not empty
   
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
    //todo
    return T();
}


#endif // _HEAP_PRIORITY_QUEUE_H_
