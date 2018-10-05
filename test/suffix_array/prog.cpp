#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <string>
#include <cassert>
#include <set>
using namespace std;
 
ifstream fin("sza.in");
 
#include "../../parts/suffix_array.cpp"
 
int z[500000];
bool cmp(int a, int b) { return z[a] < z[b]; }


int main() {
  string s;
  fin >> s;
  vector<vector<int> > P = calculateSA(s);
  for(unsigned i = 0; i < s.size(); ++i)
    z[i] = lcp(P, 0, i);
  vector<int> v;
  set<int> l;
  for(int i = 0; i < (int)s.size(); ++i) {
    l.insert(i);
    v.push_back(i);
  }
  sort(v.begin(), v.end(), cmp);
  int m = 0;
  int j = 0;
  for(int i = 1; i <= (int)s.size(); ++i) {
    while(z[v[j]] < i) {
      assert(l.find(v[j]) != l.end());
      l.erase(l.find(v[j]));
      set<int>::iterator rit = l.upper_bound(v[j]);
      int d = 0;
      if(rit != l.end()) d += *rit; else d += s.size();
      if(rit != l.begin()) { set<int>::iterator lit = rit; lit--; d -= *lit; }
       
      m = max(m, d);
      j++;
    }
    /*cout << i << endl;
    for(set<int>::iterator it = l.begin(); it != l.end(); ++it)
      cout << ' ' << *it;
      cout << endl;*/
    if(m <= i) {
      cout << m << endl;
      return 0;
    }
 
  }
  assert(0);
}
