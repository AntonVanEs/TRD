pair<int, vector<int> > 
 scc_and_top_sort(vector<vector<int> > const& heen, vector<vector<int> > const& terug) {
	vector<int> comp(heen.size());
	vector<bool> mark(heen.size(),false); int comp_n = 0;
	
	auto finished = finish_sort(heen);
	for (auto it = finished.rbegin(); it != finished.rend(); it++) {
		if (mark[*it]) { continue; }
		dfs_visit(*it, terug, [&](int cur){comp[cur] = comp_n;}, [](int){}, mark);
		comp_n++;
	}
	return make_pair(comp_n, comp);
}
