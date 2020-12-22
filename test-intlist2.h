#include<iostream>
#include "intlist.h"
#include<cstdlib>

inline void test_default_constructor_1 () {
  std::cout << "test default constructor on empty list";
  IntList list;
  std::cout << std::boolalpha <<  " *** " << ((list.size() == 0) and (list.is_empty())) << std::endl;
}
void test_print() {
  IntList list;
  int e1=1;
  int e2=2;
  int e3=3;
  list.add_front(e2);
  list.add_front(e1);
  list.add_back(e3);
  list.print();
}

inline void test_search(){
  std::cout << "test search one element"<<std::endl;
  IntList list;
  int e1=1;
  int e2=2;
  int e3=3;
  list.add_front(e1);
  list.add_front(e2);
  bool test= list.search(e1) and list.search(e2) and not(list.search(e3));
  std::cout << std::boolalpha <<  " *** " << test << std::endl;
}
