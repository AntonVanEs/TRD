#include <bits/stdc++.h>

using namespace std;

#include "../../parts/kmp.cpp"

bool check(string const& s, string const& w, vector<int> const& results) {
	std::size_t i = 0;
	bool succeed = true;
	match_string(s, w, [&](int idx) { if(i == results.size() || idx != results[i++]) {
		cerr << "fail \"" << s << "\" \"" << w << "\" match: " << idx << "\n";
		succeed = false;
	}});
	if(i != results.size()) {
		cerr << "missing matches in \"" << s << "\" \"" << w << "\" :";
		for(; i < results.size(); ++i)
			cerr << results[i];
		cerr << "\n";
		return false;
	}
	return succeed;
}

int main() {
	if(!check("aaaa", "aa", {0, 1, 2}))
		return 1;
	if(!check("abababa", "ab", {0, 2, 4}))
		return 1;
	if(!check("abcdefghijklmnop", "w", {}))
		return 1;
	if(!check("wyz", "wyz", {0}))
		return 1;
	return 0;
}