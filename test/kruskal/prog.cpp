#include <iostream>
#include <cstring>
#include <cassert>
#include <algorithm>

#define MAX_VERTICES 1000
#define MAX_EDGES (1000*1000)

/* ACPC 2006 opgave G ( http://acm-acpc.org/acpc/2006/ ) */

using namespace std;

struct edge;
void add (edge & e);

#include "../../parts/disjoint_set_forest.cpp"
#include "../../parts/kruskal.cpp"

int weight[MAX_VERTICES][MAX_VERTICES];
int total_weight;

void add (edge & e) { total_weight += e.weight; }

int marker = 0;
int reached[MAX_VERTICES];
int tree_weight;

void read_tree (int u) {
	bool simple;
	char c;
	int v;

	while (isblank (cin.peek ())) { cin.get(); }
	cin >> c;

	simple =  ('0' <= c && c <= '9');
	if (simple) { cin.putback (c); }

	cin >> v;
	reached[v-1] = marker;
	if (u) { tree_weight += weight[u-1][v-1]; }

	if (!simple) {
		while (true) {
			while (isblank (cin.peek ())) { cin.get(); }
			cin >> c;

			if (c == ')') { break; }
			cin.putback (c);

			read_tree (v);
		}
	}
}

bool check_tree (void) {
	if (marker == 0) {
		memset (reached, 0, sizeof reached);
	}
	marker++;

	tree_weight = 0;
	read_tree (0);

	if (tree_weight != total_weight) {
		return false;
	}

	for (int i = 0; i < N; i++) {
		if (reached[i] != marker) {
			return false;
		}
	}

	return true;
}

void doit (int t) {
	int Q;

	M = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			cin >> weight[i][j];
			weight[j][i] = weight[i][j];

			if (weight[i][j] > 0) {
				edges[M].u = i;
				edges[M].v = j;
				edges[M].weight = weight[i][j];
				M++;
			}
		}
	}

	total_weight = 0;
	kruskal ();

	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cout << t << '.' << i << ' '
		     << (check_tree () ? "YES" : "NO") << '\n';
	}
}

int main (void) {
	for (int i = 1; !cin.eof (); i++) {
		cin >> N;
		if (!N) { return 0; }

		doit (i);
	}

	return 0;
}
