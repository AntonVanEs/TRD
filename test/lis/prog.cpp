#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <list>

#include <cassert>

// getest op http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=6&problem=438

using namespace std;

#include "../../parts/lis.cpp"

vector<int> lijst;
void solve () {
	auto seq (longest_increasing_subsequence (lijst));

	cout << "Max hits: " << seq.size() << '\n';
	for (auto it = seq.begin(); it != seq.end(); it++) {
		cout << *it << '\n';
	}
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

		if (i < N - 1)
			cout << '\n';
	}
	return 0;
}
