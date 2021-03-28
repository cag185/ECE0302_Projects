#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "sorted_linked_list.hpp"
typedef SortedLinkedList<char> ListType;

template class SortedLinkedList<int>;

TEST_CASE("Testing isEmpty", "[sorted linked list]") {
  ListType lst;
  REQUIRE(lst.isEmpty());

  lst.insert('a');
  REQUIRE(!lst.isEmpty());

  lst.insert('b');
  REQUIRE(!lst.isEmpty());
  REQUIRE(lst.getLength() == 2);
  lst.removeAt(0);
  lst.removeAt(0);
  REQUIRE(lst.isEmpty());
}

TEST_CASE("Testing getLength", "[sorted linked list]") {
  ListType lst;
  REQUIRE(lst.getLength() == 0);

  lst.insert('b');
  REQUIRE(lst.getLength() == 1);

  lst.insert('a');
  REQUIRE(lst.getLength() == 2);

  
  lst.removeAt(0);
  
  REQUIRE(lst.getLength() == 1);
  //std::cout << "Size of list: " << lst.getLength() << std::endl;
  //std::cout << "the first remove(0) worked" << std::endl;

  lst.removeAt(0);
  //std::cout << "Working until this point" << std::endl;
  REQUIRE(lst.getLength() == 0);
  //std::cout <<"The second remove(0) worked" << std::endl;
}


TEST_CASE("Testing insert", "[sorted linked list]") {
  ListType lst;
  REQUIRE(lst.getLength() == 0);
  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  //std::cout << "the value at 0 is " << lst.getEntry(1) << std::endl;
  for (int i = 0; i < 26; ++i) {
    //std::cout << "The entry at " << i << " is " << lst.getEntry(i) << std::endl;
    REQUIRE(lst.getEntry(i) == 'a' + i);
  }
}
//THE LASt PLACE I HAVE TESTED
TEST_CASE("Testing remove", "[sorted linked list]") {
  ListType lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  lst.removeAt(5);
  REQUIRE(lst.getLength() == 25);
  REQUIRE(lst.getEntry(5) == 'g');

  lst.removeAt(11);
  REQUIRE(lst.getLength() == 24);
  REQUIRE(lst.getEntry(11) == 'n');

  //std::cout << "element at 0 : " << lst.getEntry(0) << std::endl;
 // std::cout << "element at 1 : " << lst.getEntry(1) << std::endl;
  lst.removeAt(0);
  REQUIRE(lst.getLength() == 23);
  REQUIRE(lst.getEntry(0) == 'b');

  lst.removeAt(22);
  REQUIRE(lst.getLength() == 22);
  REQUIRE(lst.getEntry(21) == 'y');
}

TEST_CASE("Testing clear", "[sorted linked list]") {
  ListType lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  lst.clear();
  REQUIRE(lst.getLength() == 0);

  c = 'a';
  while (c <= 'j') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 10);

  ListType lst_empty;
  lst_empty.clear();
  REQUIRE(lst_empty.getLength() == 0);
}


TEST_CASE("Testing getEntry", "[sorted linked list]") {
  ListType lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  for (int i = 0; i < 26; ++i) {
    REQUIRE(lst.getEntry(i) == 'a' + i);
  }
}

TEST_CASE("Testing copy", "[sorted linked list]") {
  ListType lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);
  std::cout << "here1" <<std::endl;
  ListType lst_copy = lst;
  //std::cout << "here2" << std::endl;
  //REQUIRE(lst_copy.getLength() == 26);
  //std::cout << "here" << std::endl;
  //for (int i = 0; i < 26; ++i) {
  //  std::cout << "here" << std::endl;
  //  REQUIRE(lst_copy.getEntry(i) == lst.getEntry(i));
  //}
}

/*
TEST_CASE("Testing copy empty", "[sorted linked list]") {
  ListType lst;
  ListType lst_copy = lst;

  REQUIRE(lst.getLength() == 0);
  REQUIRE(lst_copy.getLength() == 0);
}

TEST_CASE("Testing assignment", "[sorted linked list]") {
  ListType lst;
  ListType lst_copy;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  lst_copy = lst;

  REQUIRE(lst_copy.getLength() == 26);

  for (int i = 0; i < 26; ++i) {
    REQUIRE(lst_copy.getEntry(i) == lst.getEntry(i));
  }
}

TEST_CASE("Testing assignment to/from empty", "[sorted linked list]") {
  ListType lst;
  ListType lst_copy;

  lst_copy = lst;

  REQUIRE(lst.getLength() == 0);
  REQUIRE(lst_copy.getLength() == 0);
}

TEST_CASE("Testing exceptions", "[sorted linked list]") {
  ListType lst;

  CHECK_THROWS_AS(lst.removeAt(0), std::range_error);
  CHECK_THROWS_AS(lst.getEntry(0), std::range_error);

  lst.insert('a');
  lst.insert('b');
  lst.insert('c');
  lst.insert('d');

  CHECK_THROWS_AS(lst.removeAt(4), std::range_error);
  CHECK_THROWS_AS(lst.removeAt(5), std::range_error);
  CHECK_THROWS_AS(lst.getEntry(4), std::range_error);
  CHECK_THROWS_AS(lst.getEntry(5), std::range_error);

  CHECK_THROWS_AS(lst.removeAt(-1), std::range_error);
  CHECK_THROWS_AS(lst.getEntry(-1), std::range_error);
}
*/