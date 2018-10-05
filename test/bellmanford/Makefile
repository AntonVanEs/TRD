CXXFLAGS=-std=c++0x -Wall -Wextra -O2 -ggdb

test: prog
	./prog < in.txt > mine.txt
	diff -s out.txt mine.txt
	touch test

prog: prog.cpp ../../parts/bellmanford.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $(OUTPUT_OPTION) $<

clean:
	rm -f mine.txt prog test
