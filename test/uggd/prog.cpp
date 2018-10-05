#include <iostream>
#include <cassert>

using namespace std;

#include "../../parts/uggd.cpp"

template <typename T, typename U>
ostream & operator<< (ostream &o, pair <T, U> p) {
	o << '(' << p.first << ", " << p.second << ")";
	return o;
}

int main (void) {
	int a, b;
	pair <int, pair <int, int> > tmp;

	cin >> a >> b;
	while (!cin.eof ()) {
		tmp = uggd (a, b);
		assert (tmp.second.first * a + tmp.second.second * b == tmp.first);
		cout << tmp << endl;

		cin >> a >> b;
	}

	return 0;
}
