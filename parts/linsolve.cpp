

bool linsolve(vector<vector<double> > A, vector<double> b, vector<double>& x,
           unsigned rows, unsigned cols) {
	unsigned done = 0;
	for(unsigned i = 0; i < cols; ++i) {
		int r = -1;
		for(unsigned j = done; j < rows; ++j) 
			if(fabs(A[j][i]) > 1e-12) { r = j; break; }
		if(r == -1) continue;
		swap(A[done], A[r]);
		swap(b[done], b[r]);
		double dd = 1.0 / A[done][i];
		for(unsigned j = 0; j < cols; ++j)
			A[done][j] *= dd;
		b[done] *= dd;
		for(unsigned j = 0; j < rows; ++j) {
			if(done == j) continue;
			double d = A[j][i] / A[done][i];
			for(unsigned k = 0; k < cols; ++k)
				A[j][k] -= d * A[done][k];
			b[j] -= d* b[done];
		}
		done++;
	}
	if(done == cols && rows == cols) {
		for(unsigned i = 0; i < cols; ++i)
			x[i] = b[i] / A[i][i];
		return true;
	} else
		return false;
}
