vector<bool> two_sat(vector<vector<int> > const& heen, vector<vector<int> > const& terug) {
	int n = heen.size();
	vector<bool> val;
	int comp_n; vector<int> comp;
	vector<int> opp(n);
	
	tie(comp_n, comp) = scc_and_top_sort(heen, terug);
	for (int i=0; i<n; i++) { opp[comp[i]] = comp[i^1]; }
	for (int i=0; i<comp_n; i++) { if (opp[i] == i) { return val; } }
	vector<bool> cval(comp_n, false);
	for (int i=0; i<comp_n; i++) { if (!cval[i]) { cval[opp[i]] = true; } }
	for (int i=0; i<n; i++) { val.push_back(cval[comp[i]]); }
	return val;
}
