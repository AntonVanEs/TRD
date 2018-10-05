#include <bits/stdc++.h>
#define inf 100000000

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

using namespace std;

struct segment{
	int num;
	int beg, eind;
	int minIndex;
};

class SegmentTree{
public:
	SegmentTree(int n){
		ar.assign(n, inf);
		p.resize(3*n + 5); // to be sure
		p[1].num = 1; p[1].beg = 0; p[1].eind = n-1; p[1].minIndex = 0;
		for(unsigned int i = 2 ; i < p.size() ; i++){
			p[i].num = i;
			if( i%2 == 0 ){
				p[i].beg = p[i/2].beg; p[i].eind = (p[i/2].beg + p[i/2].eind)/2;}
			else{
				p[i].beg = (p[i/2].beg + p[i/2].eind)/2 + 1; p[i].eind = p[i/2].eind;}
			p[i].minIndex = p[i].beg;
		}
	}
	void update(int index, int newValue){
		ar[index] = newValue;
		update(1, index, newValue);
	}
	void update(int num, int index, int newValue){
		if( p[num].beg == p[num].eind )
			return;
		//if( ar[p[num].minIndex] > newValue)
		int mid = (p[num].beg + p[num].eind)/2;
		int num2;
		if( mid >= index )
			num *= 2;
		else
			num = 2*num+1;
		num2 = num^1;
		update(num, index, newValue);
		p[num/2].minIndex = index;
		if( ar[p[num2].minIndex] < ar[p[num/2].minIndex])
			p[num/2].minIndex = p[num2].minIndex;
		if( ar[p[num].minIndex] < ar[p[num/2].minIndex] )
			p[num/2].minIndex = p[num].minIndex;
		
	}
	int rmq(int num, int beg, int eind, int a, int b){
		if( beg >= a && eind <= b )
			return p[num].minIndex;
		if( beg > b || eind < a )
			return -1;
		
		int p1 = rmq(2*num   , beg,      (beg+eind)/2, a, b);
		int p2 = rmq(2*num +1, (beg + eind)/2+1, eind, a, b);
		if(p1 == -1)
			return p2;
		else{
			if( p2 == -1)
				return p1;
			return (ar[p1] < ar[p2] ? p1 : p2);
		}	
	}
	int rmq(int a, int b){
		return rmq(1,0,ar.size()-1,a,b);
	}
	vector<segment> p;
	vi ar;
};

int main(){
	SegmentTree st(7);
	int a, b;
	char c;
	while( true){
		cin >> c >> a >> b;
		if( c == 'u'){
			st.update(a, b);
		}
		else{
			cout << st.rmq(a, b) << endl;
		}
	}
	return 0;
}
