#include "dynamic_array_list.h"
#include "sorted_list.h"
#include "priority_queue.h"

int main()
{
  typedef SortedList<int, DynamicArrayList<int> > SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;

  std::cout << "is empty? : " << pq.isEmpty() << std::endl;
  pq.add(1);
  std::cout << "the peek value: " << pq.peek() << std::endl;
  pq.add(2);
  std::cout << "the peek value: " << pq.peek() << std::endl;
  pq.add(3);
  std::cout << "the peek value: " << pq.peek() << std::endl;
  pq.add(4);
  std::cout << "the peek value: " << pq.peek() << std::endl;
  std::cout << "is empty? : " << pq.isEmpty() << std::endl;

  std::cout << "remove" << std::endl;
  pq.remove();
  std::cout << "the peek value: " << pq.peek() << std::endl;
  std::cout << "remove" << std::endl;
  pq.remove();
  std::cout << "the peek value: " << pq.peek() << std::endl;
  std::cout << "remove" << std::endl;
  pq.remove();
  std::cout << "the peek value: " << pq.peek() << std::endl;
  std::cout << "remove" << std::endl;
  pq.remove();
  std::cout << "is empty? : " << pq.isEmpty() << std::endl;

  return 0;
}
