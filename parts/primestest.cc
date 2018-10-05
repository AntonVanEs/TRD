#include <bits/stdc++.h>

using namespace std;

template<class T>
pair <T, pair <T, T> > uggd(T a, T b) {
	T x, lastx, y, lasty;
	T q;

	x = lasty = 0;
	y = lastx = 1;

	while (b != 0) {
		q = a / b;

		a %= b;
		swap(a,b);

		lastx -= q*x;
		swap(x, lastx);

		lasty -= q*y;
		swap(y, lasty);
	}

	return make_pair (a, make_pair (lastx, lasty));
}

template<class T>
T crt(T a, T b, T m, T n){ //assumes m, n are coprime
	pair<T,T> multinv = uggd(m,n).second;
	T x = b*((multinv.first*m)%(m*n)) + a*((multinv.second*n)%(m*n));
	x = (x%(m*n) + m*n)%(m*n); 
	return x;
} // returns 0 <= x < m*n with x = a (mod m), x = b (mod n)

int main(){
	cout << crt(3,4,5,7) << endl;
}
