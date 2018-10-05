#include <bits/stdc++.h>
/* NWERC 2008 opgave B */

using namespace std;

#define MAX_NODES 20000

int m;
bool in[MAX_NODES];
bool out[MAX_NODES];

vector<vector<int>> heen;
vector<vector<int>> terug;



#include "../../parts/dfs.cpp"
#include "../../parts/finishsort.cpp"
#include "../../parts/scc.cpp"

void doit () {
	int n;
	int i, c, d;
	int u, v;

	cin >> n >> m;
	
	heen.clear();
	heen.resize(n);
	terug.clear();
	terug.resize(n);

	for (i = 0; i < m; i++) {
		cin >> u >> v;
		heen[u-1].push_back (v-1);
		terug[v-1].push_back (u-1);
	}
	
	int comp_n;
	vector<int> comp;

	tie(comp_n, comp) = scc_and_top_sort (heen, terug);

//	for (i = 0; i < n; i++) {
//		cerr << i << ' ' << comp[i] << endl;
//	}

	if (comp_n == 1) {
		cout << 0 << endl;
		return;
	}

	memset (in, 0, sizeof in);
	memset (out, 0, sizeof out);

	for (i = 0; i < n; i++) {
		for (vector<int>::iterator it = heen[i].begin ();
		     it != heen[i].end ();
		     ++it) {
			if (comp[i] != comp[*it]) {
				out[comp[i]] = true;
				in[comp[*it]] = true;
			}
		}
	}

	c = d = 0;
	for (i = 0; i < comp_n; i++) {
		c += in[i] ? 0 : 1;
		d += out[i] ? 0 : 1;
	}
	cout << max (c, d) << endl;

}

int main () {
	int t, i;
	cin >> t;
	for (i = 0; i < t; i++) {
		doit ();
	}
}
