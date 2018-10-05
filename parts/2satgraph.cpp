// the ith variable corresponds to nodes 2i and 2i+1 in the graph
// 2i is true if the variable is true, 2i+1 if it is false
struct graph {
	vector<vector<int> > heen, terug; // the arguments of 2sat
	graph(n) : heen(2*n), terug(2*n) {} // graph with nodes for n vars
	int add_clause(int a, int b) { // a & b are nodes, adds clause (a or b)
		heen[a^1].push_back(b); terug[b].push_back(a^1);
		heen[b^1].push_back(a); terug[a].push_back(b^1);
	}
}; // 2sat gives output for both nodes of a variable
