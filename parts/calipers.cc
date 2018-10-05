typedef long long T;
typedef valarray<T> coord;

T cross( coord a, coord b ) {
	return a[0]*b[1]-a[1]*b[0];
}

int line_intersect_location( coord p1, coord p2, coord q1, coord q2 ) {
	return cross( p2-p1, q2-q1 );
}

double length( coord a, coord b ) {
	return sqrt(double(((a-b)*(a-b)).sum()));
}

tuple<double,int,int> diameter( vector<coord> hull ) {
	double d = 0;
	int n = hull.size(), a = 0, b = 0, ap, bp;
	while( line_intersect_location( hull[a], hull[a+1], hull[(b+1)%n], hull[(b+2)%n] ) < 0 )
		++b;
	int s = b;
	while( a < n or b < s + n ) {
		double l = length( hull[a%n], hull[b%n] );
		if( l > d ) {
			d = l;
			ap = a%n;
			bp = b%n;
		}
		if( line_intersect_location( hull[a%n], hull[(a+1)%n], hull[b%n], hull[(b+1)%n] ) < 0 )
			++b;
		else
			++a;
	}
	return tuple<double,int,int>(d,ap,bp);
}
