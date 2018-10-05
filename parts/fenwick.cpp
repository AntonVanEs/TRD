void inc (unsigned i, int delta) {
	while (i < (unsigned)n) { f[i] += delta; i |= i+1; }
}
int exclsum (unsigned k) { // sum_{i=0}^{k-1} a[i]
	int ret = 0;
	while (k > 0) { ret += f[k-1]; k &= k-1; }
	return ret;
}
