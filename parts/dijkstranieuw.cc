typedef int distType; // of "typedef double distType", etcetera
typedef pair<distType, int> pijl;
typedef vector<pijl> vp;
typedef vector<vp> graaf;

int dijkstra(int s, int t, graaf buren){
	priority_queue <pijl, vp, greater<pijl> > q;
	vector<distType> dist(buren.size(), numeric_limits<distType>::max()/3);
	dist[s] = 0;
	q.push ({dist[s], s});
	while (!q.empty ()) {
		pijl cur = q.top();
		q.pop();
		if( dist[cur.second] < cur.first){continue;}
		if( cur.second == t)
			return dist[cur.second];
		for( auto it = buren[cur.second].begin();
		    it != buren[cur.second].end(); ++it){
			if (cur.first + it->first < dist[it->second]) {
				dist[it->second] = cur.first + it->first;
				q.push ({dist[it->second], it->second});
			}
		}
	}
	return -1; // target niet bereikbaar
}
