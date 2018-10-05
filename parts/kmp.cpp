// s: haystack, w: needle, cb: match callback with word start
template<class F>
void match_string(string const& s, string const& w, F&& cb) {
	assert(!w.empty());
	vector<int> f(w.size() + 1, 0);
	for(unsigned i = 2, c = 0; i <= w.size();) {
		if(w[i-1] == w[c]) f[i++] = ++c;
		else if(c > 0) c = f[c];
		else ++i;
	}
	for(unsigned i = 0, q = 0; i < s.size(); ++i) {
		while(q > 0 && (q == w.size() || s[i] != w[q])) q = f[q];
		if(w[q] == s[i]) ++q;
		if(q == w.size()) cb(i + 1 - w.size());
	}
}