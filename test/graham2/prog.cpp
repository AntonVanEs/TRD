#include <cstdlib>
#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

typedef long long int coord_t;
typedef int naam_t;
#include "../../parts/geom.cpp"
#include "../../parts/dot.cpp"
#include "../../parts/cross.cpp"
#include "../../parts/direction.cpp"
#include "../../parts/graham.cpp"

int main (void) {
	int n, m;
	vector<punt> punten;
	list<list<punt> > hull;

	cin >> n;
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		punten.clear();
		hull.clear();

		cin >> m;
		for (int j = 0; j < m; j++) {
			int x, y;
			cin >> x >> y;
			punten.push_back (punt (x, y, j));
		}

		if (m >= 2) {
			// FIXME: check voor dubbele punten!
			graham_scan (punten, hull);

			cout << hull.size() << endl;
			for (list<list<punt> >::iterator it1 = hull.begin(); it1 != hull.end(); ++it1) {
				cout << it1->back().naam << endl;
			}
		} else {
			cout << 1 << endl << 0 << endl;
		}

		if (i != n-1) { cout << endl; }
	}

	return 0;
}
