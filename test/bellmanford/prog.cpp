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

#define MAX_W 30
#define MAX_H 30
#define MAX_NODES (MAX_W*MAX_H)
#define MAX_ARCHES (4*MAX_NODES)

/* SWERC 2009 opgave F */

using namespace std;

const int deltax[4] = {-1, 0, 0, 1};
const int deltay[4] = {0, -1, 1, 0};

struct gat {
	unsigned x2, y2;
	int t;
};

unsigned n;

unsigned w, h;
char yard[MAX_W][MAX_H];
gat hole[MAX_W][MAX_H];

#include "../../parts/bellmanford.cpp"

vector<int> dist;
vector<pijl<int>> pijlen;

void dump (void) {
	unsigned x, y;
	unsigned j;

	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++) {
			cout << yard[x][y];
		}
		cout << endl;
	}

	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++) {
			cout << dist[x*h+y] << " ";
		}
		cout << endl;
	}

	for (j = 0; j < dist.size(); j++) {
		cout << pijlen[j].a/h << "," << pijlen[j].a%h << "--" << pijlen[j].l << "--" << pijlen[j].b/h << "," << pijlen[j].b%h << endl;
	}
}

void doit (void) {
	unsigned g, i, e;
	int x, y, x1, y1, x2, y2, t;

	memset (yard, '.', sizeof yard);
	pijlen.clear();

	cin >> g;
	for (i = 0; i < g; i++) {
		cin >> x >> y;
		yard[x][y] = '#';
	}

	cin >> e;
	for (i = 0; i < e; i++) {
		cin >> x1 >> y1 >> x2 >> y2 >> t;

		yard[x1][y1] = '*';
		hole[x1][y1].x2 = x2;
		hole[x1][y1].y2 = y2;
		hole[x1][y1].t = t;
	}

	for (x = 0; (unsigned)x < w; x++) {
		for (y = 0; (unsigned)y < h; y++) {
			if ((unsigned)x == w-1 && (unsigned)y == h-1) { continue; } // stop when exit reached

			if (yard[x][y] == '*') {
				pijlen.push_back({x*h+y, hole[x][y].x2*h + hole[x][y].y2, hole[x][y].t});
				//pijlen[m].a = x*h+y;
				//pijlen[m].b = hole[x][y].x2*h + hole[x][y].y2;
				//pijlen[m].l = hole[x][y].t;
				//m++;
				continue;
			}

			for (i = 0; i < 4; i++) {
				if (x+deltax[i] < 0 || (unsigned)(x+deltax[i]) >= w
				    || y+deltay[i] < 0 || (unsigned)(y+deltay[i]) >= h) {
					continue;
				}

				switch (yard[ x+deltax[i] ][ y+deltay[i] ]) {
				case '.':
				case '*':
					pijlen.push_back({x*h + y, (x+deltax[i])*h + (y+deltay[i]), 1});
					//pijlen[m].a = x*h + y;
					//pijlen[m].b = (x+deltax[i])*h + (y+deltay[i]);
					//pijlen[m].l  = 1;
					//m++;
					break;
				case '#':
					break;
				default:
					assert (false);
				}
			}
		}
	}

	if (!bellmanford (0,n,pijlen,dist)) {
		cout << "Never" << endl;
	} else if (dist[n-1] >= INT_MAX/4) {
		cout << "Impossible" << endl;
	} else {
		cout << dist[n-1] << endl;
	}
	//dump ();
}

int main (void) {
	while (true) {
		cin >> w >> h;
		n = w*h;
		if (n == 0) { break; }
		doit ();
	}

	return 0;
}
