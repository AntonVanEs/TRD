template<class DistType>
struct pijl {
	unsigned a,b;
	DistType l; // signed!
};

template<class DistType>
bool bellmanford (unsigned s, unsigned n, vector<pijl<DistType>> const& pijlen,
		vector<DistType> &dist) {
	unsigned m = pijlen.size();
	
	dist.clear();
	dist.resize(n, numeric_limits<DistType>::max()/2);
	dist[s] = 0;

	for (unsigned i = 0; i < n; i++) {
		for (unsigned j = 0; j < m; j++) {
			dist[pijlen[j].b] = min(dist[pijlen[j].b], dist[pijlen[j].a] + pijlen[j].l);
		}
	}

	// return alleen false bij negatieve kringen die bereikt kunnen worden
	for (unsigned j = 0; j < m; j++) {
		if (dist[pijlen[j].a] < numeric_limits<DistType>::max()/4 && 
		     dist[pijlen[j].b] > dist[pijlen[j].a] + pijlen[j].l)
			return false;
	}

	return true;
}
