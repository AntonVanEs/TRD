tuple<vector<map<char,int>>,vector<int>, vector<vector<int>>>
 build_table(vector<string> const& patterns) {
	vector<map<char,int>> follow;
	vector<vector<int>> match;
	
	follow.push_back(map<char,int>());
	match.push_back(vector<int>());
	
	for (unsigned i=0; i<patterns.size(); i++) {
		int cur = 0;
		for (auto c : patterns[i]) {
			if (follow[cur].count(c) != 0) {
				cur = follow[cur][c];
			} else {
				follow[cur][c] = follow.size();
				cur = follow.size();
				follow.push_back(map<char,int>());
				match.push_back(vector<int>());
			}
		}
		match[cur].push_back(i);
	}
	
	vector<int> fail(follow.size(), -1);
	queue<pair<int, char>> work;
	for (auto kv : follow[0]) { work.push({0, kv.first}); }
	while (!work.empty()) {
		auto curfull = work.front();
		int cur = curfull.first;
		char followChar = curfull.second;
		work.pop();
		for (auto kv : follow[follow[cur][followChar]]) { 
			work.push({follow[cur][followChar], kv.first});
		}
		int curf = fail[cur];
		while (curf != -1) {
			if (follow[curf].count(followChar) == 0) { curf = fail[curf]; }
			else { curf = follow[curf][followChar]; break; }
		}
		if (curf == -1) { curf = 0; }
		fail[follow[cur][followChar]] = curf;
		if (curf != 0) {
			match[follow[cur][followChar]].insert(match[follow[cur][followChar]].end(),
				match[curf].begin(), match[curf].end());
		}
	}
	
	return make_tuple(follow, fail, match);
}

// cb has last char of match, index of matched word as args.
template<class F>
void match_table(string const& s, tuple<vector<map<char,int>>,vector<int>,
  vector<vector<int>>> const& table, F&& cb) {
	auto const& follow = get<0>(table);
	auto const& fail = get<1>(table);
	auto const& match = get<2>(table);
	
	int state = 0;
	for (unsigned i=0; i<s.size(); i++) {
		auto it = follow[state].find(s[i]);
		if (it == follow[state].end()) {
			if (state != 0) { state = fail[state]; i--; }
		} else {
			state = it->second;
			for (auto m : match[state])	{ cb(i, m); }
		}
	}
}
