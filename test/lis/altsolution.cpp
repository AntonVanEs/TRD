#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

#include "aantallen.h"

using namespace std;

vector<int> lijst;
vector<int> gesorteerd;
int c[LENGTE+1][LENGTE+1];

void solve() {
	int l, k;
	// magic happens!

	k = (int) lijst.size();

	gesorteerd = lijst;
	sort(gesorteerd.begin(), gesorteerd.end());
	gesorteerd.resize (unique(gesorteerd.begin(), gesorteerd.end()) - gesorteerd.begin ());
	l = gesorteerd.size ();
	
	for (int i = 0; i < l; i++) {
		c[i][0] = 0;
	}
	for (int i = 0; i < k; i++) {
		c[0][i] = 0;
	}
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= k; j++) {
			if (gesorteerd[i-1] == lijst[j-1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else {
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
			}
		}
	}
	cout << "Max hits: " << c[l][k] << endl;
}

int main() {
	string str;
	stringstream ss(stringstream::in);
	int N;

	// Line with number of cases N
	getline (cin, str);
	ss.str (str);
	ss >> N;

	// empty line
	getline(cin, str);

	for (int i = 0; i < N; i++) {
		lijst.clear();

		getline(cin, str);
		while (!cin.fail() && !ss.fail() && !str.empty()) {
			// read height of a missile
			int temp;
			ss.clear ();
			ss.str (str);

			ss >> temp;
			lijst.push_back(temp);

			getline(cin, str);
		}
		solve ();

		//if (i < N - 1)
			//cout << '\n';
	}
	return 0;
}
