#include <cstdlib>
#include <cstring>
#include <iostream>

/* NCPC 2011 Opgave B: Mega Inversions */
/* I/O beetje aangepast om 1 bestand te gebruiken. */

using namespace std;

int n;
int a[100000];
int f[100000];
int voorgroter[100000];

void clear (void) { memset (f, 0, sizeof f); }

#include "../../parts/fenwick.cpp"

void doit (void) {
	long long som = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}

	clear ();
	for (int i = 0; i < n; i++) {
		voorgroter[i] = i - exclsum (a[i]+1);
		inc (a[i], 1);
	}

	clear ();
	for (int i = n - 1; i >= 0; i--) {
		som += voorgroter[i] * (long long)exclsum (a[i]);
		inc (a[i], 1);
	}

	cout << som << endl;
}

int main (void) {
	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {
		doit ();
	}

	return 0;
}
