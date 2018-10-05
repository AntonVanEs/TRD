#include <cassert>
#include <iostream>

using namespace std;
#include "../../parts/isprime.cpp"


const long long BOVENGRENS = 1e8;
bool isprimea[BOVENGRENS + 1];

void zeef() {
	for (int i = 0; i <= BOVENGRENS; i++) isprimea[i] = true;
	isprimea[0] = isprimea[1] = false;
	for (long long i = 0; i <= BOVENGRENS; i++) {
		if (!isprimea[i]) continue;
		//cout << i << endl;
		for (long long j = i * i; j <= BOVENGRENS; j += i)
			isprimea[j] = false;
	}
}


int main() {
	zeef();
	for(unsigned long long i = 0; i <=BOVENGRENS; ++i) {
		if(i % 1000000 == 0) cout << "at " << i << endl;
		if(isprime(i) != isprimea[i]) {
			cout << i << " " << isprime(i) << " " << isprimea[i] << endl;
			assert(isprime(i) == isprimea[i]);
		}
	}
}
