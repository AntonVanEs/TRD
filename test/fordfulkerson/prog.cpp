#include <bits/stdc++.h>

#define ABS(a) ((a) >= 0 ? (a) : -(a))

/* NWERC 2005 opgave H */

using namespace std;

#define MAX_NODES 502

#include "../../parts/flowgraph.cpp"
int n;
int height[MAX_NODES];
char sex[MAX_NODES];
string music[MAX_NODES];
string sport[MAX_NODES];

void doit () {
	int s, t;

	// lees in
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> height[i] >> sex[i] >> music[i] >> sport[i];
	}

	FlowGraph<int, int> g(n + 2);
	// maak graaf
	s = 0;
	t = 1;
	for (int i = 0; i < n; i++) {
		if (sex[i] == 'M') {
			g.connect (s, i + 2, 1, 0);
		} else {
			g.connect (i + 2, t, 1, 0);
		}

		for (int j = 0; j < i; j++) {
			if (sex[i] != sex[j] && ABS(height[i]-height[j]) <= 40
			    && (music[i] == music[j]) && sport[i] != sport[j]) {
				if (sex[i] == 'M') {
					g.connect (i + 2, j + 2, 1, 0);
				} else {
					g.connect (j + 2, i + 2, 1, 0);
				}
			}
		}
	}

	// run max-flow
	cout << n - g.ford_fulkerson(s, t).first << endl;
}

int main () {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		doit ();
	}
	return 0;
}
