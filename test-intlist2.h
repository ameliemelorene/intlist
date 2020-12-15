#include<iostream>
#include "intlist.h"
#include<cstdlib>

inline void test_default_constructor_1 () {
  std::cout << "test default constructor on empty list";
  IntList list;
  std::cout << std::boolalpha <<  " *** " << ((list.size() == 0) and (list.is_empty())) << std::endl;
}
