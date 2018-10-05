CXXFLAGS=-std=c++0x -Wall -Wextra -O2 -ggdb

test: prog ../../aux/comp
	./prog < in.txt > mine.txt
	../../aux/comp out.txt mine.txt -7
	touch test

../../aux/comp: ../../aux/comp.cpp
	cd ../../aux/ && ${MAKE} comp

prog: prog.cpp ../../parts/dijkstra.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $(OUTPUT_OPTION) $<

clean:
	rm -f mine.txt prog test
