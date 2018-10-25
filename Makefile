CXX = clang++
CXXFLAGS += -g -std=c++11 -Wall
LDFLAGS += -g -lstdc++

%.o: %.cxx
	$(CXX) $(CXXFLAGS) -c $<

# .PHONY:
# clean:
# 	rm -f *.o
