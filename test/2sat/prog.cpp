/****
 * NWERC 2011 -- Problem D: Piece it together
 ****/

#include <bits/stdc++.h>

#define MAXR 500
#define MAXK 500
#define MAXB ((500*500)/3)
#define MAXN (4*MAXB)
#define MAX_NODES MAXN

using namespace std;

vector<vector<int>> heen;
vector<vector<int>> terug;


bool val[MAXN];

#include "../../parts/dfs.cpp"
#include "../../parts/finishsort.cpp"
#include "../../parts/scc.cpp"
#include "../../parts/2sat.cpp"

int maxr, maxk;
char grid[MAXR+2][MAXR+4]; // bit extra for newline
int var[MAXR+2][MAXR+2];

/*
 *  0
 * 2B3
 *  1
 */

void imply (int i, int j) {
	heen[i].push_back (j);
	heen[j^1].push_back (i^1);

	terug[j].push_back (i);
	terug[i^1].push_back (j^1);
}

void set_false (int i) {
	heen[i].push_back (i^1);
	terug[i^1].push_back (i);
}

bool doit () {
	int b, w;
	bool res;

	b = w = 0;

	for (int r = 1; r <= maxr; r++) {
		for (int k = 1; k <= maxk; k++) {
			switch (grid[r][k]) {
				case 'B': b++; break;
				case 'W': w++; break;
				default: break;
			}
		}
	}

	if (2*b != w) { return false; }
	
	heen.clear();
	terug.clear();

	/* create nodes, automatically demand Left-Right and Up-Down, deny on non-white */
	for (int r = 1; r <= maxr; r++) {
		for (int k = 1; k <= maxk; k++) {
			if (grid[r][k] == 'B') {
				var[r][k] = heen.size();
				heen.push_back(vector<int>());
				heen.push_back(vector<int>());
				heen.push_back(vector<int>());
				heen.push_back(vector<int>());
				terug.push_back(vector<int>());
				terug.push_back(vector<int>());
				terug.push_back(vector<int>());
				terug.push_back(vector<int>());

				if (grid[r-1][k] != 'W') { set_false (var[r][k]+0); }
				if (grid[r+1][k] != 'W') { set_false (var[r][k]+1); }
				if (grid[r][k-1] != 'W') { set_false (var[r][k]+2); }
				if (grid[r][k+1] != 'W') { set_false (var[r][k]+3); }
			}
		}
	}

	/* demand non-overlapping */
	for (int r = 1; r <= maxr; r++) {
		for (int k = 1; k <= maxk; k++) {
			if (grid[r][k] == 'W') {
				int c = 0; int l[4];
				if (grid[r-1][k] == 'B') { l[c++] = var[r-1][k]+1; }
				if (grid[r+1][k] == 'B') { l[c++] = var[r+1][k]+0; }
				if (grid[r][k-1] == 'B') { l[c++] = var[r][k-1]+3; }
				if (grid[r][k+1] == 'B') { l[c++] = var[r][k+1]+2; }

				for (int i = 0; i < c; i++) {
					for (int j = 0; j < c; j++) {
						if (i != j) { imply (l[i], l[j] ^ 1); }
					}
				}
			}
		}
	}
	/* now any solution necessarily fills all white squares, because of their number */
	
	auto sol = two_sat(heen, terug);
	res = (sol.size() != 0);
	return res;
}

int main (void) {
	char line[502];
	int t;

	fgets (line, sizeof line, stdin);
	sscanf (line, "%i", &t);
	for (int i = 0; i < t; i++) {
		fgets (line, sizeof line, stdin);
		sscanf (line, "%i %i", &maxr, &maxk);

		for (int k = 0; k <= maxk+1; k++) { grid[0][k] = '.'; }
		for (int r = 1; r <= maxr; r++) {
			grid[r][0] = ' ';
			fgets (grid[r]+1, sizeof grid[r], stdin);
			grid[r][maxk+1] = '.';
		}
		for (int k = 0; k <= maxk+1; k++) { grid[maxr+1][k] = '.'; }

		if (doit()) {
			fprintf (stdout, "YES\n");
		} else {
			fprintf (stdout, "NO\n");
		}
	}
}
