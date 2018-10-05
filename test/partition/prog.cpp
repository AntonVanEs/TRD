#include <algorithm>
#include <iostream>

using namespace std;

#define P 14

#include "../../parts/partition.cpp"

int main () {
	for (int i = 0; i < P; i++) {
		cout << partition(i) << endl;
	}

	return 0;
}
