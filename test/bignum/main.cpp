#include <bits/stdc++.h>

using namespace std;

#include "../../parts/bignum.cpp"


string get_string(bignum b) {
	ostringstream oss;
	b.print(oss);
	return oss.str();
}

string get_string(long long b) {
	ostringstream oss;
	oss << b;
	return oss.str();
}


int main() {
	for(long long l = -1000000; l <= 1000000; ++l) {
		if(get_string(bignum(l)) != get_string(l))
			return 1;
		if((bignum(l) < 0) != (l < 0))
			return 1;
	}
	mt19937 rng;
	uniform_int_distribution<long long> rand(0, 1ull << 62);
	for(unsigned i = 0; i < 1000000; ++i) {
		auto a = rand(rng);
		auto b = rand(rng) + 1;
		if(get_string(bignum(a) / bignum(b)) != get_string(a/b)) {
			cerr << " failed " << a << " / " << b << " : " << get_string(bignum(a) / bignum(b)) << " " <<  get_string(a/b) << "\n";
			return 1;
		}
	}
}
