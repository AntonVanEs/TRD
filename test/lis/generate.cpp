#include <iostream>
#include <cstdlib>
#include <ctime>

#include "aantallen.h"

using namespace std;


int main() {
	int seed = time(NULL);
	cerr << "Seed: " << seed << endl;
	srand(seed);
	cout << AANTAL_CASES << endl;
	for (int i = 0; i < AANTAL_CASES; i++) {
		cout << endl;
		for (int j = 0; j < LENGTE; j++) {
			cout << rand () % 10000 << endl;
		}
	}
	return 0;
}
