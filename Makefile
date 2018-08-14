TARGETS=ex_8queen ex_segment_tree
CXXFLAGS=-std=c++14 -g
CXX=g++ -Wall

ex_8queen: ex_8queen.cxx
	$(CXX) $(CXXFLAGS) -o $@ $<

.PHONY:
clean:
	rm -f ex_8queen ex_segment_tree