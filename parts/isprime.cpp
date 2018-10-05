__int128_t power(__int128_t a, unsigned long long e, unsigned long long n) {
	if(e == 1) return a;
	if(e & 1) return (a * power(a, e-1, n) % n);
	__int128_t v = power(a, e/2, n);
	return (v*v) % n;
}

bool isprime(unsigned long long n) {
	if(n <= 1) return false;
	unsigned long long d = n-1;
	unsigned s = 0;
	while(d % 2 == 0) { d /= 2; ++s; }
	// BELANGRIJK: typ deze getallen goed over!
	const unsigned a_arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	for(unsigned i = 0; i < sizeof(a_arr)/sizeof(unsigned) && a_arr[i] < n; ++i) {
		unsigned a = a_arr[i];
		__int128_t v = power(a, d, n);
		if(v == 1) continue;
		bool composite = true;
		for(unsigned p = 0; p < s; ++p) {
			if(v == n-1) { composite = false; break; }
			v = (v * v) % n;
		}
		if(composite) return false;
	}
	return true;
}
