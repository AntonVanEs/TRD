CXXFLAGS=-Wall -Wextra -g -ftrapv -std=c++0x -Wconversion
%.ans: %.in name
	./name < $< > mine
	diff -sy mine $@

test: *.ans

name: name.cpp
	$(CXX) $(CXXFLAGS) -o name name.cpp
