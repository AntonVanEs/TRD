#include <cstdlib>
#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

typedef int coord_t;
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
	int count[256], cornercount[256];

	cin >> n;
	for (int i = 0; i < n; i++) {
		punten.clear();
		hull.clear();
		memset (count, 0, sizeof(count));
		memset (cornercount, 0, sizeof(cornercount));

		cin >> m;
		for (int j = 0; j < m; j++) {
			int x, y;
			cin >> x >> y;
			punten.push_back (punt (x, y, j));
		}

		graham_scan (punten, hull);

		for (list<list<punt> >::iterator it1 = hull.begin(); it1 != hull.end(); ++it1) {
			for (list<punt>::iterator it2 = it1->begin(); it2 != it1->end(); ++it2) {
				count[(int)it2->naam]++;
			}
			cornercount[(int)it1->back().naam]++;
		}

		cout << hull.size();
		cout << " #";
		for (int j = 0; j < m; j++) {
			cout << " " << count[j];
		}
		cout << " #";
		for (int j = 0; j < m; j++) {
			cout << " " << cornercount[j];
		}
		cout << endl;
	}

	return 0;
}
