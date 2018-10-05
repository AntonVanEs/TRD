const int limb_max = 10000;
class bignum {
private:
	bool sign = false;
	vector<int> limbs;
public:
	bignum() {}
	bignum(long long a) {
		sign = a<0;
		a = abs(a);
		while (a) {
			limbs.push_back(a%limb_max);
			a /= limb_max;
		}
	}

	void norm() {
		size_t tlen = limbs.size();
		while (tlen && limbs[tlen-1] == 0) tlen--;
		limbs.resize(tlen);
	}

	void comp(vector<int> &a) const
	{
		for (auto &p : a)
			p = limb_max-p-1;
		if (a.size() != 0) a[0]++;
		int i=0;
		while (a[i] == limb_max){
			a[i] = 0; i++; if (i == a.size()) break; a[i]++;
		}
	}

	void prim_add(vector<int> const& a, vector<int> const& b,
		vector<int> & c) const {
		assert(a.size() == b.size());
		size_t siz = a.size();
		c.reserve(siz+1);
		int carry = 0;
		for (unsigned i = 0; i<siz; i++) {
			int val = a[i]+b[i]+carry;
			carry = val >= limb_max ? 1 : 0;
			c.push_back(val - carry * limb_max);
		}
		if (carry) c.push_back(carry);
	}

	bignum doAS(bignum const &bb, bool inv) const {
		vector<int> a = limbs;
		vector<int> b = bb.limbs;
		bool bbsign = bb.sign;
		if (inv && !b.empty()) bbsign = !bbsign;
		size_t siz = max(a.size(), b.size());
		a.resize(siz,0);
		b.resize(siz,0);
		if (bbsign != sign) {
			comp(sign ? a : b);
		}
		bignum res;
		prim_add(a,b,res.limbs);
		if (bbsign != sign) {
			res.sign = false;
			if (res.limbs.size() == siz+1)
				res.limbs.pop_back();
			else {
				res.sign = true;
				comp(res.limbs);
			}
		} else res.sign = sign;
		res.norm();
		return res;
	}

	bignum operator+(bignum const &bb) const {
		return doAS(bb, false);
	}

	bignum operator-(bignum const &bb) const {
		return doAS(bb, true);
	}

	bool operator<(bignum const &bb) const {
		bignum r = *this - bb;
		return r.sign;
	}

	bignum operator*(bignum const &b) const {
		bignum res;
		res.limbs.resize(limbs.size() + b.limbs.size(),0);
		for (unsigned i=0; i<limbs.size(); i++) {
			for (unsigned j=0; j<b.limbs.size(); j++) {
				res.limbs[i+j] += limbs[i] * b.limbs[j];
				unsigned k=i+j;
				while (res.limbs[k] >= limb_max) {
					res.limbs[k+1] += res.limbs[k] / limb_max;
					res.limbs[k] %= limb_max;
					k++;
				}
			}
		}
		if (res.limbs.back() == 0) res.limbs.pop_back();
		res.sign = !(sign == b.sign);
		return res;
	}

	bignum operator/(bignum const &D) const
	{
		if (*this < D) return 0;
		if (D.limbs.size() == 1 && D.limbs[0] == 1) return *this;
		int N = 2*limbs.size();
		bignum Dunit;
		Dunit.limbs.resize(N+1,0);
		Dunit.limbs.back() = 2;
		bignum invD;
		invD.limbs.resize(N-D.limbs.size()+1,0);
		invD.limbs.back() = limb_max/D.limbs.back();

		int totIter = 30 + ceil(log2(N));

		for (int iter = 0; iter < totIter; iter++)
		{
			bignum temp = invD * (Dunit - D * invD);
			for (int i=0; i<invD.limbs.size(); i++)
			{
				invD.limbs[i] = temp.limbs[N+i];
			}
			invD.norm();
		}

		Dunit.limbs.back() = 1;
		while (invD * D < Dunit) invD = invD + 1;
		bignum temp = invD * (*this);
		bignum res;
		res.limbs.resize(temp.limbs.size()-N);
		for (int i=0; i<res.limbs.size(); i++)
			res.limbs[i] = temp.limbs[N+i];
		res.norm();
		return res;
	}

	void print(ostream &o) const {
		if(limbs.empty()) { o << '0'; return; }
		if (sign)
			o << '-';
		o << limbs.back();
		for (int i=limbs.size()-2; i>=0; i--)
			o << setw(4) << setfill('0') << limbs[i];
	}
};
