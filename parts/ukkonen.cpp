// char_type is type of symbol
// t[] should be a container with [] containing the source string
const int INF = numeric_limits<int>::max();

struct sEdge { int node; int start, end; }; //start, end includsive, 1 indexd
struct sNode {
	map<char_type, sEdge> edges;
	int f;
};

vector<sNode> sTree; int algs, algk, algi; sEdge fake;
sEdge &gf(int s, char_type ta) {
	if (s == 0) { fake.node = 1; fake.start = fake.end = -1; return fake;
	} else { return sTree[s].edges[ta]; }
}

bool have(int s, char_type ta) {
	if (s == 0) return true;
	return sTree[s].edges.count(ta) != 0;
}

pair<bool, int> test_and_split(int s, int k, int p, 
									char_type ta) {
	if (k <= p) {
		auto &g = gf(s, t[k-1]);
		if (ta == t[g.start+p-k]) return {true, s}; else {
			int r = sTree.size(); sTree.push_back(sNode());
			sTree[r].edges[t[g.start+p-k]] = {g.node, g.start+p-k+1, g.end};
			g.end = g.start+p-k; g.node = r; return {false, r};
		}
	} else {
		if (have(s,ta) == 0) return {false, s};
		else return {true,s};
	}
}

pair<int, int> canonize(int s, int k, int p) {
	if (p < k) return {s,k};
	auto g = gf(s, t[k-1]);
	while (g.end - g.start <= p-k) {
		k = k + g.end - g.start + 1; s = g.node;
		if (k <= p) g = gf(s,t[k-1]);
	}
	return {s,k};
}

pair<int, int> update(int s, int k, int i) {
	int r; bool endpoint; int oldr = 1;
	tie (endpoint,r) = test_and_split(s, k, i-1, t[i-1]);
	while (!endpoint) {
		int rp = sTree.size(); sTree.push_back(sNode());
		sTree[r].edges[t[i-1]] = {rp, i, INF};
		if (oldr != 1) sTree[oldr].f = r;
		oldr = r; tie(s,k) = canonize(sTree[s].f, k, i-1);
		tie(endpoint,r) = test_and_split(s, k, i-1, t[i-1]);
	}
	if (oldr != 1) sTree[oldr].f = r;
	return {s,k};
}

void init() { 
	sTree.resize(2); sTree[1].edges.clear(); sTree[1].f = 0;
	algs=1; algk = 1; algi=0;
}

void add() {
	algi++;
	tie(algs,algk) = update(algs, algk, algi);
	tie(algs,algk) = canonize(algs, algk, algi);
}
