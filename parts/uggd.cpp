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
