vector<int> finish_sort(vector<vector<int> > const& buren) {
	vector<int> finished; vector<bool> mark(buren.size());
	int n = buren.size();
	for (int i = 0; i < n; i++) { 
		dfs_visit (i, buren, [](int){},
			[&](int cur){finished.push_back(cur);}, mark);
	}
	return finished;
}
