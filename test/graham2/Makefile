CXXFLAGS=-std=c++0x -Wall -Wextra -O2 -ggdb

test: prog compare
	./prog < convexhull.in > my.out
	./compare
	touch test

compare: compare.cpp

prog: prog.cpp ../../parts/geom.cpp ../../parts/dot.cpp ../../parts/cross.cpp ../../parts/direction.cpp ../../parts/graham.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $(OUTPUT_OPTION) $<

clean:
	rm -f my.out prog test compare
