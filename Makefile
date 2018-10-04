TARGETS= ex_8queen ex_8queen2 ex_segment_tree ex_bisection
CXXFLAGS= -std=c++14 -g -Wall
CXX=g++

all: $(TARGETS)

ex_8queen: ex_8queen.cxx
	$(CXX) $(CXXFLAGS) -o $@ $<

ex_8queen2: ex_8queen2.cxx
	$(CXX) $(CXXFLAGS) -o $@ $<

ex_segment_tree: ex_segment_tree.cxx
	$(CXX) $(CXXFLAGS) -o $@ $<

ex_bisection: ex_bisection.cxx
	$(CXX) $(CXXFLAGS) -o $@ $<

.PHONY:
clean:
	rm -rf $(TARGETS) *.dSYM
