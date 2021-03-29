#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.h"
#include "queue.h"

#include <cassert>

TEST_CASE("Testing 1", "[queue]") {
  // a queue, holding ints, using a DynamicArrayList as the container
  Queue<int, DynamicArrayList<int>> queue;

  REQUIRE(queue.isEmpty() == 1);
  //std::cout << "working till here" << std::endl;
  queue.enqueue(12);
  //std::cout << "the beginning of the queue is : " << queue.peekFront() << std::endl;
 // std::cout << "working till here" << std::endl;
  REQUIRE(!queue.isEmpty());
  //std::cout << "working till here" << std::endl;
  REQUIRE(queue.peekFront() == 12);
  //std::cout << "working till here" << std::endl;
  queue.enqueue(-4);
  //std::cout << "working till here" << std::endl;
  REQUIRE_FALSE(queue.isEmpty());
  REQUIRE(queue.peekFront() == 12);

  queue.dequeue();
  //std::cout << "working till here1" << std::endl;
  
  queue.dequeue();
  //std::cout << "working till here2" << std::endl;
  REQUIRE(queue.isEmpty());

  //writng my own cases
  queue.enqueue(4);
  queue.enqueue(5);
  queue.enqueue(6);
  REQUIRE(queue.peekFront()== 4);
  queue.dequeue();
  std::cout << "works till right here" << std::endl;
  REQUIRE(queue.peekFront() == 5);
  queue.dequeue();
  REQUIRE(queue.peekFront() == 6);
  queue.dequeue();
  REQUIRE(queue.isEmpty());


  queue.enqueue(241);
  REQUIRE_FALSE(queue.isEmpty());
  REQUIRE(queue.peekFront() == 241);

  queue.enqueue(45);
  REQUIRE(!queue.isEmpty());
  REQUIRE(queue.peekFront() == 241);

  queue.enqueue(62);
  REQUIRE_FALSE(queue.isEmpty());
  REQUIRE(queue.peekFront() == 241);
  std::cout << "works here" << std::endl;

  Queue<int, DynamicArrayList<int>> another_queue;
  another_queue = queue;
  std:: cout << "huh" << std::endl;

  REQUIRE_FALSE(another_queue.isEmpty());
  REQUIRE(another_queue.peekFront() == 241);
  another_queue.dequeue();
  REQUIRE(another_queue.peekFront() == 45);
  another_queue.dequeue();
  REQUIRE(another_queue.peekFront() == 62);
}