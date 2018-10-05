vector<int> longest_increasing_subsequence (vector<int> const& lijst) {
	if (lijst.empty()) { return {}; }

 	int n(lijst.size ());
	vector<int> P(n), M(1), seq;
	// P[i] is the predecessor i in a longest increasing subsequence of
	// lijst[0..i] containing element i.
	// M[k] is de index van het eind van de sequence met lengte k + 1
	// met laagste eindwaarde.

	P[0] = -1;

	for (int i = 1; i < n; i++) {
		// de lengte van de langste sequence waar lijst[i] achter kan
		auto j = M.begin();
		if (lijst[M[0]] < lijst[i]) {
			j = lower_bound (M.begin(), M.end(), i,
					 [&](int a, int b) { return lijst[a] < lijst[b]; });
		}

		P[i] = (j != M.begin()) ? *(j - 1) : -1;

		if (j == M.end()) {
			M.push_back(i);
		} else if (lijst[i] < lijst[*j]) {
			*j = i;
		}
	}

	for (int a = M.back(); a >= 0; a = P[a]) {
		seq.push_back (lijst[a]);
	}

	reverse(seq.begin(), seq.end());
	return seq;
}
