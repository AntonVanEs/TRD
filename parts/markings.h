template <int n> struct markings {
	unsigned data[n];
	unsigned marker;
	struct ref {
		unsigned &p; unsigned marker;
		ref (unsigned &_p, unsigned _m) : p(_p), marker(_m) { }
		ref & operator= (bool v) { p = (v ? marker : 0); return *this; }
		operator bool (void) { return p == marker; }
	};

	markings (void) : marker(1) { memset (data, 0, sizeof data); }
	void reset (void) {
		marker++;
		if (marker == 0) { memset (data, 0, sizeof data); marker++; }
	}
	ref operator[] (int i) { return ref (data[i], marker); }
};
