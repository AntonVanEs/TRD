test: subdir/name.cxx subdir/Makefile subdir/name.in subdir/name.ans
	cd subdir && ${MAKE}
	touch test

subdir/name.in:
	echo 0 > subdir/name.in

subdir/name.ans:
	touch subdir/name.ans

subdir/name.cxx: subdir ../../parts/name.cpp
	cp ../../parts/name.cpp subdir

subdir/Makefile: subdir ../../parts/Makefile
	cp ../../parts/Makefile subdir

subdir:
	mkdir subdir

clean:
	rm -rf subdir test
