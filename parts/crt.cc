template<class T>
T crt(T a, T b, T m, T n){ //assumes m, n are coprime
	pair<T,T> multinv = uggd(m,n).second;
	T x = b*((multinv.first*m)%(m*n)) + a*((multinv.second*n)%(m*n));
	x = (x%(m*n) + m*n)%(m*n); 
	return x;
} // returns 0 <= x < m*n with x = a (mod m), x = b (mod n)
