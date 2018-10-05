void find_lis(vector<int> &a, vector<int> &b) {
	vector<int> p(a.size());
	int u, v;
	if (a.empty()) return;
	b.push_back(0);
	for (size_t i = 1; i < a.size(); i++) {
		if (a[b.back()] < a[i]) {    //If next element a[i] is greater than last 
			p[i] = b.back();         //   element of current longest subsequence 
			b.push_back(i);          // a[b.back()], just push it at back of "b" 
			continue;
		}
		// search for smallest element referenced by b  just bigger than a[i]
		for (u = 0, v = b.size()-1; u < v;) {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}
		if (a[i] < a[b[u]]) {                // Update b if new value is smaller 
			if (u > 0) p[i] = b[u-1];        // then previously referenced value
			b[u] = i;                    
		}	
	}
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}
