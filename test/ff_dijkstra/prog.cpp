#include <bits/stdc++.h>

using namespace std;

#include "../../parts/flowgraph.cpp"


bool doit () {
	int N, M, s, t;
	cin >> N;
	if(!N) return false;
	cin >> M >> s >> t;

	FlowGraph<int, int> g(N);
	for(int i = 0; i < M; ++i) {
		int a, b, c, rc, cc;
		cin >> a >> b >> c >> rc >> cc;
		g.connect(a,b,c,rc,cc);
	}
	auto p = g.ford_fulkerson(s, t);
	cout << p.first << " " << p.second << endl;
	return true;
}

int main () {
	for (int i = 0; doit(); i++) 
		;
	return 0;
}
