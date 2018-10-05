CXXFLAGS=-std=c++0x -Wall -Wextra -O2 -ggdb

test: prog in.txt out.txt
	./prog < in.txt | grep Max > mine.txt
	diff -s out.txt mine.txt
	touch test

prog: prog.cpp ../../parts/lis.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $(OUTPUT_OPTION) $<

generate: generate.cpp aantallen.h

altsolution: altsolution.cpp aantallen.h

in.txt: generate
	./generate > in.txt

out.txt: in.txt altsolution
	./altsolution < in.txt > out.txt

clean:
	rm -f mine.txt prog test altsolution generate in.txt out.txt
