#include <bits/stdc++.h>

using namespace std;

#include "../../parts/ahocorasick.cpp"

void doit()
{
	int N;
	
	cin >> N;
	vector<string> dict;
	for (int i=0; i<N; i++)
	{
		string cur;
		cin >> cur;
		dict.push_back(cur);
	}
	
	auto table = build_table(dict);
	
	string toMatch;
	cin >> toMatch;
	
	vector<int> count(dict.size(), 0);
	
	match_table(toMatch, table, [&](int i, int m) {count[m]++;});
	
	for (unsigned i=0; i<count.size(); i++)
	{
		if (i != 0) cout << " ";
		cout << count[i];
	}
	cout << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int i=0; i<T; i++) doit();
	return 0;
}
