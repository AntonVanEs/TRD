vector<int> buren[MAX_NODES];
bool visited[MAX_NODES];
int low[MAX_NODES];
int d[MAX_NODES];
vector<pair<int, int> > st;

void mark(int a, int b) {
  pair<int, int> e;
  do {
    e = st.back();
    st.pop_back();
    // doe iets met de tak
  } while((e.first != a || e.second != b) && (e.first != b || e.second != a));
}

void dfs(int n, int parent, int& count) {
  visited[n] = true;
  low[n] = d[n] = ++count;
  for(unsigned i = 0; i <buren[n].size(); ++i) {
    int v = buren[n][i];
    if(!visited[v]) {
      st.push_back(make_pair(n,v));
      dfs(v, n, count);
      if(low[v] >= d[n]) {
        mark(n,v); // als n niet de root is dan n is een cut vertex
      }
      low[n] = min(low[n], low[v]);
    } else if(parent != v && d[v] < d[n]) {
      st.push_back(make_pair(n,v));
      low[n] = min(low[n], d[v]);
    }
  }
  // root == cut vertex <=> als er 2+ kinderen direct vanuit de root visited zijn.
}


void bicon(int N) {
  int count = 0;
  st.clear();
  fill_n(visited, N, false);
  for(unsigned i = 0; i < N; ++i)
    if(!visited[i])
      dfs(i, -1, count);
}
