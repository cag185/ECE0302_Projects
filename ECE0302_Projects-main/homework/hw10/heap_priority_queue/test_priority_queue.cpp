#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "heap_priority_queue.h"

TEST_CASE("Test Construction", "[construction]") {
  HeapPriorityQueue<int>  pq;
  REQUIRE(pq.isEmpty());
}

TEST_CASE("Test add", "[add]") {
  HeapPriorityQueue<int>  pq;
  pq.add(25);

  REQUIRE(!pq.isEmpty());
  REQUIRE(pq.peek() == 25);

  pq.add(1);
  REQUIRE(pq.peek() == 25);

  pq.add(78);
  REQUIRE(pq.peek() == 78);
  pq.add(50);
  pq.add(2);
  pq.add(35);
  REQUIRE(pq.peek() == 78);

  pq.add(99);
  REQUIRE(pq.peek() == 99);
}

TEST_CASE("Test remove", "[remove]") {
  HeapPriorityQueue<int>  pq;
  pq.add(25);
  pq.add(1);
  pq.add(78);

  pq.remove();
  REQUIRE(pq.peek() == 25);
  pq.remove();
  REQUIRE(pq.peek() == 1);
  pq.remove();
  REQUIRE(pq.isEmpty());
}
TEST_CASE("test remove again", "[remove]")
{
  HeapPriorityQueue<int> q;
  q.add(1);
  q.add(25);
  q.add(99);

  REQUIRE(q.peek() == 99);
  q.remove();
  REQUIRE(q.peek() == 25);
  q.remove();
  REQUIRE(q.peek() == 1);

  //add more
  q.add(5);
  q.add(10);
  REQUIRE(q.peek() == 10);
  q.add(58);
  REQUIRE(q.peek() == 58);
  q.add(120);
  REQUIRE(q.peek() == 120);
  std::cout << "THE PROBLEM IS HERE: " << std::endl;
  q.remove();
  REQUIRE(q.peek() == 58);
}
