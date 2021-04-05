#include "dynamic_array_list.h"
#include "sorted_list.h"

int main()
{
  typedef SortedList<int, DynamicArrayList<int> > slst;
  //test adding items
  slst list;
  std:: cout << "the size: " << list.getLength() << std::endl;
  list.insert(1);
  std:: cout << "the size: " << list.getLength() << std::endl;
  list.insert(2);
  std:: cout << "the size: " << list.getLength() << std::endl;
  list.insert(3);
  std:: cout << "the size: " << list.getLength() << std::endl;
  list.insert(4);
  std:: cout << "the size: " << list.getLength() << std::endl;
  list.insert(5);
  std:: cout << "the size: " << list.getLength() << std::endl;
  std::cout << "position of 1: " <<list.getEntry(1) << std::endl;
  std::cout << "position of 2: " <<list.getEntry(2) << std::endl;
  std::cout << "position of 3: " <<list.getEntry(3) << std::endl;
  std::cout << "position of 4: " <<list.getEntry(4) << std::endl;

  
  return 0;
}
