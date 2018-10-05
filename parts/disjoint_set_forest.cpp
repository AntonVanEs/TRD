int parent[MAX_VERTICES], rnk[MAX_VERTICES];

void init (int v) { parent[v] = v; rnk[v] = 0; }

int representant (int v) { // met path reduction
	return (parent[v] == v) ? v : (parent[v] = representant (parent[v]));
}

void merge (int u, int v) { // met union by rnk
	assert (parent[u] == u && parent[v] == v);
	if (rnk[u] < rnk[v]) { parent[u] = v; }
	else if (rnk[u] > rnk[v]) { parent[v] = u; }
	else { parent[u] = v; rnk[v]++; }
}
