#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"
#include <iostream>
using namespace std;

// TODO -- implementing tests of the deque
template class Deque<int>;

TEST_CASE( "Tests", "[deque]" ) 
{
    Deque<int> d;
    REQUIRE(d.isEmpty() == 1);
}
