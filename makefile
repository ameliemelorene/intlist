CXX=g++
CXXFLAGS=-Wall -ggdb
RM=rm -f

intlist : test-intlist.o
  $(CXX) $(CXXFLAGS) $^ -o $@

test-intlist.o : test-intlist2.h intlist.h

%.o: %.cpp; $(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
  $(RM) test_intlist.o intlist
