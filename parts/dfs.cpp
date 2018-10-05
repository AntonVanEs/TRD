template <typename S, typename F>
void dfs_visit (int cur, vector<vector<int> > const& buren, S start, F finish,
	vector<bool> &mark) {
	if (mark[cur]) { return; }
	mark[cur] = true;

	start (cur);
	for (auto nb : buren[cur]) {
		dfs_visit (nb, buren, start, finish, mark);
	}
	finish (cur);
}
