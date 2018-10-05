int N, M;
struct edge { int u, v; int weight; } edges[MAX_EDGES];

bool cmp (const edge & e, const edge & f) { return e.weight < f.weight; }

void kruskal (void) {
	sort (edges, edges + M, cmp); // sorteer kanten
	for (int i = 0; i < N; i++) { init (i); } // elke knoop een eigen component

	for (int i = 0; i < M; i++) { // itereer in oplopende volgorde
		int u = representant (edges[i].u), // verkrijg representanten van de
            v = representant (edges[i].v); // componenten van edges[j].{u,v}

		if (u != v) { // als verschillende componenten: merge
			add (edges[i]); // voeg toe aan minimum spanning tree in wording
			merge (u, v);
		}
	}
}
