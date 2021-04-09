#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"
#include <iostream>
using namespace std;

// Student Tests -- implementing tests of the deque
//template class Deque<int>;

//looks good so far
TEST_CASE( "IsEmpty", "[deque]" ) 
{
    Deque<int> d;
    REQUIRE(d.isEmpty() == 1);
}

//very nice
TEST_CASE( "PushFront", "[deque]" ) 
{
    Deque<int> d;
    d.pushFront(1);
    //since we added one, is empty is false
    REQUIRE (d.isEmpty()==0);
    
}

//sir yes sir
TEST_CASE( "PopFront", "[deque]" ) 
{
    Deque<int> d;
    //should not be able to pop without entry
    REQUIRE_THROWS_AS(d.popFront(), std::runtime_error);
    //add an item
    d.pushFront(1);
    REQUIRE(!d.isEmpty());
    REQUIRE(d.getLength() == 1);
    d.popFront();
    REQUIRE(d.isEmpty());
}

//front works well
TEST_CASE( "Front", "[deque]" ) 
{
    Deque<int> d;
    //test that we cannot return a front value in an empt deque
    REQUIRE_THROWS_AS(d.front(), std::runtime_error);
    //items should be added in order FILO
    d.pushFront(1);
    d.pushFront(2);
    d.pushFront(3);
    REQUIRE(d.getLength() ==3);
    REQUIRE(!d.isEmpty());
    REQUIRE(d.front() == 3);
    d.popFront();
    REQUIRE(d.getLength() == 2);
    REQUIRE(d.front() == 2);
    d.popFront();
    REQUIRE(d.getLength() == 1);
    REQUIRE(d.front() == 1);
}


TEST_CASE( "PushBack", "[deque]" ) 
{
    Deque<int> d;
    //items shold be appended to the back
    REQUIRE(d.isEmpty());
    d.pushBack(3);
    d.pushBack(2);
    d.pushBack(1);
    REQUIRE(d.getLength() == 3);
    REQUIRE(d.back() == 1);
    
}

TEST_CASE( "PopBack", "[deque]" ) 
{
    Deque<int> d;
    
}

TEST_CASE( "Back", "[deque]" ) 
{
    Deque<int> d;
    
}

TEST_CASE( "Copy Constructor", "[deque]" ) 
{
    Deque<int> d;
}

TEST_CASE( "Copy Assignment", "[deque]" ) 
{
    Deque<int> d;
}