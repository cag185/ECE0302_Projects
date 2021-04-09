#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"
#include <iostream>
using namespace std;

// Student Tests -- implementing tests of the deque
//template class Deque<int>;

TEST_CASE( "IsEmpty", "[deque]" ) 
{
    Deque<int> d;
    REQUIRE(d.isEmpty() == 1);
}
TEST_CASE( "PushFront", "[deque]" ) 
{
    Deque<int> d;
    d.pushFront(1);
    REQUIRE (d.isEmpty()==0);
    
}

TEST_CASE( "PopFront", "[deque]" ) 
{
    Deque<int> d;
    
}

TEST_CASE( "Front", "[deque]" ) 
{
    Deque<int> d;
    
}

TEST_CASE( "PushBack", "[deque]" ) 
{
    Deque<int> d;
    
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