template<class Cap, class Cost>
struct FlowGraph {
	FlowGraph(size_t sz) : out(sz), potential(sz), dist(sz), pred(sz) {}

	void connect(unsigned s, unsigned t, Cap cap, Cap revcap, Cost cost = 0) {
		assert(!revcap || !cost);

		out[s].push_back(edges.size());
		edges.push_back({t, cap, cost});
		out[t].push_back(edges.size());
		edges.push_back({s, revcap, -cost});
	}

	pair<Cap, Cost> ford_fulkerson(unsigned s, unsigned t) { // s != t
		Cap total = 0;
		Cost cost = 0;
		while (find_dijkstra(s, t)) {
			auto flow = numeric_limits<Cap>::max();
			for (auto i = t; i != s; i = edges[pred[i]^1].dest)
				flow = min(flow, edges[pred[i]].cap);

			cost += potential[t] * flow;
			total += flow;

			for (auto i = t; i != s; i = edges[pred[i]^1].dest) {
				edges[pred[i]].cap -= flow;
				edges[pred[i]^1].cap += flow;
			}
		}
		return {total, cost};
	}

private:
	using halfpijl = pair<Cost, unsigned>;
	bool find_dijkstra(unsigned s, unsigned t) {
		dist = numeric_limits<Cost>::max()/2;
		dist[s] = 0;
		pred[t] = t;
		priority_queue<halfpijl, vector<halfpijl>, greater<halfpijl> > q;
		q.push(make_pair(0, s));

		while (!q.empty()) {
			halfpijl p = q.top(); q.pop();
			if (p.first > dist[p.second]) continue;
			for (auto e : out[p.second]) {

				int c = edges[e].cost + potential[p.second] - potential[edges[e].dest];
				if (edges[e].cap && dist[edges[e].dest] > p.first + c) {
					pred[edges[e].dest] = e;
					dist[edges[e].dest] = p.first + c;
					q.push(make_pair(p.first + c,  edges[e].dest));
				}
			}
		}
		if(pred[t] == t)
			return false;

		potential += dist;
		return true;
	}

	vector<vector<unsigned>> out;
	struct Edge {
		unsigned dest;
		Cap cap;
		Cost cost;
	};
	vector<Edge> edges;

	valarray<Cost> potential, dist;
	vector<unsigned> pred;
};
