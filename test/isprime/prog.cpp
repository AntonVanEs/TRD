#include <iostream>

using namespace std;

#include "../../parts/isprime.cpp"

int main (void) {
	unsigned long long x;

	cin >> x;
	while (!cin.eof ()) {
		cout << (isprime(x) ? 1 : 0) << endl;
		cin >> x;
	}

	return 0;
}
