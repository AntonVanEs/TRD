// Fenwick tree/binary indexed tree: dynamic range queries
// find sum of range: 		lg(n)
// change value at index: 	lg(n)
struct f_tree {
	vl data;
	ll n;		// size

	f_tree(ll n) : n(n) {
		data.assign(n, 0);
	}

	void add(ll idx, ll delta) {	// add to item at idx
		for (; idx < n; idx = idx | (idx + 1))
			data[idx] += delta;
	}

	ll sum(ll idx) { 	// compute sum of elements 0,..,r
		ll ret = 0;
		for (; idx >= 0; idx = (idx & (idx + 1)) - 1)
			ret += data[idx];
		return ret;
	}
};
