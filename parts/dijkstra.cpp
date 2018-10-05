template<class DistType>
using halfpijl = pair<DistType, unsigned>;

template<class DistType>
DistType dijkstra (unsigned s, unsigned t, 
		vector<vector<halfpijl<DistType>>> const& buren) {
	priority_queue <halfpijl<DistType>,
	                vector <halfpijl<DistType>>,
	                greater <halfpijl<DistType>> > q;
	
	vector<DistType> dist(buren.size(), numeric_limits<DistType>::max());

	dist[s] = 0;
	q.push ({dist[s], s});

	while (!q.empty ()) {
		auto cur = q.top ();
		q.pop ();

		if (dist[cur.second] < cur.first) { continue; }

		if (cur.second == t) {
			return dist[t];
		}

		for (auto it = buren[cur.second].begin ();
		     it != buren[cur.second].end ();
		     ++it) {
			if (cur.first + it->first < dist[it->second]) {
				dist[it->second] = cur.first + it->first;
				q.push ({dist[it->second], it->second});
			}
		}
	}
	return dist[t];
}
