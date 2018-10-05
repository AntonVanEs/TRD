#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>

#include <iostream>

#include <utility>
#include <functional>
#include <algorithm>

#define MAX_PORTS 1000
#define MAX_NODES (2*MAX_PORTS+2)

/* SWERC 2009 opgave G */

using namespace std;

unsigned n;

//hekje h heeft nodes 2*h, 2h+1. begin is 2*n, finish is 2*n+1
#include "../../parts/dijkstra.cpp"

double px1[MAX_PORTS], px2[MAX_PORTS], py[MAX_PORTS];
double sx, sy;

template <typename T> T sqr (T a) { return a*a; }

void emitpath (double x1, double y1, double x2, double y2) {
	cout << "<path style=\"stroke:#000000;stroke-width:0.01px;\" d=\"M " << x1 << "," << y1 << " " << x2 << "," << y2 << "\"/>" << endl;
}

void emitpoint (double x, double y, const char *name) {
	cout << "<text style=\"font-size:0.2px;\" x=\"" << x << "\" y=\"" << y << "\"><tspan>" << name << "</tspan></text>" << endl;
}

vector<vector<halfpijl<double>>>buren;

// p is hoogste hekje waar nog doorheen moet
void addlines (unsigned cur, double x, double y, unsigned h) {
	double min, max, left, right;

	buren[cur].clear ();

	min = -INFINITY;
	max = INFINITY;

	// recht naar een pole
	for (; h < n; h++) {
		left = (px1[h]-x) / (y-py[h]);
		right = (px2[h]-x) / (y-py[h]);

		if (min <= left && left <= max) {
			buren[cur].push_back (
				make_pair(sqrt(sqr(px1[h]-x) + sqr (y-py[h])), 2*h));
			//emitpath (x, y, px1[h], py[h]);
		}

		if (min <= right && right <= max) {
			buren[cur].push_back (
				make_pair(sqrt(sqr(px2[h]-x) + sqr (y-py[h])), 2*h+1));
			//emitpath (x, y, px2[h], py[h]);
		}

		if (min < left) {
			min = left;
		}
		if (right < max) {
			max = right;
		}
	}

	// recht naar finish
	if (min <= 0 && 0 <= max && px1[n-1] <= x && x <= px2[n-1]) {
			buren[cur].push_back (make_pair(y-py[n-1], 2*n+1));
			//emitpath (x, y, x, py[n-1]);
	}
}

void doit (void) {
	unsigned i;
	char buf[20];
	
	buren.clear();
	buren.resize(2*n+2);

	cin >> sx >> sy;
	//emitpoint (sx, sy, "s");
	for (i = 0; i < n; i++) {
		cin >> py[i] >> px1[i] >> px2[i];

		sprintf (buf, "p%u", i);
		//emitpoint (px1[i], py[i], buf);
		sprintf (buf, "q%u", i);
		//emitpoint (px2[i], py[i], buf);
	}

	addlines (2*n, sx, sy, 0);
	for (i = 0; i < n; i++) {
		addlines (2*i, px1[i], py[i], i+1);
		addlines (2*i+1, px2[i], py[i], i+1);
	}

	printf ("%.11lf\n", dijkstra (2*n, 2*n+1, buren));
	/*for (i = 0; i < 2*n+2; i++) {
		cout << "(pred, dist)[" << i << "] == (" << pred[i] << ", " << dist[i] << ")" << endl;
	}*/
}

int main (void) {
	while (true) {
		cin >> n;
		if (n == 0) { break; }
		//cout << "<g>" << endl;
		doit ();
		//cout << "</g>" << endl;
	}

	return 0;
}
