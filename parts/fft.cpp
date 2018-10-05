vector<complex<double>> fft_part(complex<double> const* x, int sz, int stride = 1) {
	if(sz == 1)
		return {*x};
	auto l = fft_part(x, sz / 2, stride * 2);
	auto r = fft_part(x + stride, sz / 2, stride * 2);
	vector<complex<double>> ret(sz);
	for(int i = 0; i < sz / 2; ++i) {
		ret[i] = l[i] + r[i] * exp(- 2.0 * M_PI * i / sz * complex<double>{0, 1});
		ret[i+sz/2] = l[i] - r[i] * exp(- 2.0 * M_PI * i / sz * complex<double>{0, 1});
	}
	return ret;
}

vector<complex<double>> fft(vector<complex<double>> const& x, int sz) {
	return fft_part(x.data(), sz);
}

vector<complex<double>> defft(vector<complex<double>> x, int sz) {
	std::reverse(x.begin()+1, x.end());
	auto result = fft_part(x.data(), sz);
	for(auto& e : result)
		e /= static_cast<double>(sz);
	return result;
}
