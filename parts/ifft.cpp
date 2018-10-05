typedef long long ll;
typedef unsigned long long ull;

const ll p = 9223372034170421249LL;
const ll root = 5576881676563514300LL;
ll invroot;
const int rootSize = (1LL<<29);

pair <ll, pair <ll, ll> > uggd(ll a, ll b) {
	ll x, lastx, y, lasty;
	ll q;

	x = lasty = 0;
	y = lastx = 1;

	while (b != 0) {
		q = a / b;

		a %= b;
		swap(a,b);

		lastx -= q*x;
		swap(x, lastx);

		lasty -= q*y;
		swap(y, lasty);
	}

	return make_pair (a, make_pair (lastx, lasty));
}

struct Fp { ull val; Fp(){} Fp(ull v){val=v;}};
Fp operator+(Fp a, Fp b) { return Fp((a.val+b.val)%p); }
Fp operator-(Fp a, Fp b) { return Fp((p+a.val-b.val)%p); }
Fp operator*(Fp a, Fp b) { return Fp(ull((__int128_t(a.val)*b.val)%p)); }
Fp inv(Fp a) {
	ll inv = uggd(a.val, p).second.first;
	while (inv < 0) inv += p;
	while (inv >= p) inv -= p;
	return Fp(inv);
}
Fp operator/(Fp a, Fp b) { return a * inv(b); }
Fp pow(Fp a, int n) {
	Fp res(1);
	while (n) {
		if (n & 1) res = res * a;
		a = a * a; n /= 2;
	}
	return res;
}

vector<Fp> fft_part(Fp const* x, int sz, int stride = 1) {
	if(sz == 1)
		return {*x};
	auto l = fft_part(x, sz / 2, stride * 2);
	auto r = fft_part(x + stride, sz / 2, stride * 2);
	vector<Fp> ret(sz);
	Fp omega = pow(Fp(root), rootSize/sz);
	Fp omegaP = 1;
	for(int i = 0; i < sz / 2; ++i) {
		ret[i] = l[i] + r[i] * omegaP;
		ret[i+sz/2] = l[i] - r[i] * omegaP;
		omegaP = omegaP * omega;
	}
	return ret;
}

vector<Fp> fft(vector<Fp> const& x, int sz) {
	return fft_part(x.data(), sz);
}

vector<Fp> defft(vector<Fp> x, int sz) {
	std::reverse(x.begin()+1, x.end());
	auto result = fft_part(x.data(), sz);
	Fp isz = inv(Fp(sz));
	for(auto& e : result)
		e = e*isz;
	return result;
}
