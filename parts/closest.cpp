double closest_dfs(const vector<pair<double, double> >& xs,
                    const vector<pair<double, double> >& ys) {
    if(xs.size() <= 1)
    	return INFINITY;
	pair<double, double> m = xs[xs.size()/2];
	vector<pair<double, double> > xa,xb, ya, yb, ys2;
	for(unsigned i = 0; i < xs.size(); ++i) {
		if(xs[i] < m) xa.push_back(xs[i]); else xb.push_back(xs[i]);
		if(ys[i] < m) ya.push_back(ys[i]); else yb.push_back(ys[i]);
	}

	double a = closest_dfs(xa, ya), b = closest_dfs(xb, yb);
	double d = min(a,b);
	for(unsigned i = 0; i < ys.size(); ++i)
		if(ys[i].first >= m.first - d && ys[i].first <= m.first+d)
			ys2.push_back(ys[i]);
	for(unsigned i = 0; i < ys2.size(); ++i)
		for(unsigned j = i + 1; j < ys2.size() && j < i + 30; ++j)
			d = min(d, dist(ys2[i], ys2[j])); 
	
	return d;
}

bool cmpy(pair<double, double> a, pair<double, double> b) {
 return a.second != b.second ? a.second < b.second : a.first < b.first; }
 
double closest(const vector<pair<double, double> >& v) {
	vector<pair<double, double> > xs = v, ys = v;
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end(), cmpy);
	for(unsigned i = 0; i +1 < xs.size(); ++i) if(xs[i] == xs[i+1]) return 0.0;
	return closest_dfs(xs, ys);
}
