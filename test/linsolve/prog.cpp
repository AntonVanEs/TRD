#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#include "../../parts/linsolve.cpp"

bool doit() {
	int n, m;
	cin >> n >> m;
	if(!cin) return false;
	vector<vector<double> > A(n, vector<double>(m));
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> A[i][j];
	vector<double> b(n);
	for(int i = 0; i < n; ++i) cin >> b[i];
	vector<double> x(m);
	
	if(linsolve(A, b, x, n, m)) {
		for(int i = 0; i < m; ++i)  {
			if(i) cout << ' ';
			cout << x[i];
		}
		cout << endl;
	} else
		cout << "Not invertible" << endl;
	return true;
}

int main() {
	while(doit()) ;
	return 0;
}
