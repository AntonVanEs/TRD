#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream reference("convexhull.out", ifstream::in);
ifstream my("my.out", ifstream::in);

int n,m;
vector<int> refnums, mynums;

bool compare() {
	bool mislukt = false;
	reference >> n;
	my >> m;
	if (m != n)
		mislukt = true;
	refnums.resize(m);
	mynums.resize(m);
	int b = -1;
	for (int i = 0; i < max(m,n); i++) {
		if (i < n)
			reference >> refnums[i];
		if (i < m) {
			my >> mynums[i];
			if (mynums[i] == refnums[0]) {
				if (b != -1)
					mislukt = true;
				b = i;
			}
		}
	}
	if (b == -1)
		mislukt = true;
	for (int i = 0; i < n; i++) {
		int k = (b + i) % m;
		if (mynums[k] != refnums[i])
			mislukt = true;
	}
	return !mislukt;
}

int main() {
	int Na, Nb;
	reference >> Na;
	my >> Nb;
	if (Na != Nb) {
		cout << "Number of testcases mismatch." << endl;
		return 1;
	}
	int correct = 0;
	for (int i = 0; i < Na; i++) {
//		cout << "Case " << i << ": ";
		if (compare()) {
//			cout << "CORRECT" << endl;
			correct++;
		}
//		else
//			cout << "INCORRECT" << endl;
	}
	cout << "Correctly solved " << correct << " out of " << Na << " testcases." << endl;
	return (correct == Na) ? 0 : 1;
}
