CXXFLAGS=-std=c++0x -Wall -Wextra -O2 -ggdb

test: prog
	./prog < in.txt > mine.txt
	diff -s mine.txt out.txt
	touch test

prog: prog.cpp ../../parts/geom.cpp ../../parts/dot.cpp ../../parts/cross.cpp ../../parts/direction.cpp ../../parts/graham.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $(OUTPUT_OPTION) $<

clean:
	rm -f mine.txt prog test
