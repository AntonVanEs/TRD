struct Entry { 
  int nr[2];
  int p;
  bool operator<(const Entry& o) const {
    if(nr[0] != o.nr[0]) return nr[0] < o.nr[0];
    if(nr[1] != o.nr[1]) return nr[1] < o.nr[1];
    return p < o.p;
  }
};
 
vector<vector<int> > calculateSA(const string& s) {
  vector<vector<int> > P(ceil(log2(s.size()))+2, vector<int>(s.size()));
  vector<Entry> ve(s.size());
  for(unsigned i = 0; i < s.size(); ++i)
    P[0][i] = s[i] - 'a';
  for(int stp=1, cnt=1; cnt >> 1 < (int)s.size(); ++stp, cnt <<=1) {
    for(unsigned i = 0; i < s.size(); ++i) {
      ve[i].nr[0] = P[stp-1][i];
      ve[i].nr[1] = i + cnt < s.size() ? P[stp-1][i+cnt] : -1;
      ve[i].p = i;
    }
    sort(ve.begin(), ve.end());
    for(unsigned i = 0; i < s.size(); ++i)
      P[stp][ve[i].p] = (i > 0 && ve[i].nr[0] == ve[i-1].nr[0] &&
                                  ve[i].nr[1] == ve[i-1].nr[1]) ? P[stp][ve[i-1].p] : i;
  }
  return P;
}
 
vector<unsigned> calculateSuffixArray(const string& s) {
	vector<vector<int> > order = calculateSA(s);
	vector<pair<int, unsigned> > v(s.size());
	for(unsigned i = 0; i < s.size(); ++i) v[i] = make_pair(order.back()[i], i);
	sort(v.begin(), v.end());
	vector<unsigned> sa(s.size());
	for(unsigned i = 0; i < s.size(); ++i) sa[i] = v[i].second;
	return sa;
} 


int lcp(const vector<vector<int> >& P, unsigned x, unsigned y) {
  if(x == y) return P.front().size() - x;
  int ret = 0;
  for(int k = P.size()-1; k >= 0 && x < P.front().size() &&
                                    y < P.front().size(); --k)
    if(P[k][x] == P[k][y])
      x += 1 << k, y += 1 << k, ret += 1 << k;
  return ret;
}
