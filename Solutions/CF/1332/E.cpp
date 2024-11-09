#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

/**
 * Author: Ulf Lundstrom
 * Date: 2009-08-03
 * License: CC0
 * Source: My head
 * Description: Basic operations on square matrices.
 * Usage: Matrix<int, 3> A;
 *  A.d = {{{{1,2,3}}, {{4,5,6}}, {{7,8,9}}}};
 *  vector<int> vec = {1,2,3};
 *  vec = (A^N) * vec;
 * Status: tested
 */

#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
#define MOD 998244353LL

template<class T, int N> struct Matrix {
	typedef Matrix M;
	array<array<T, N>, N> d{};
	M operator*(const M& m) const {
		M a;
		rep(i,0,N) rep(j,0,N)
				rep(k,0,N) (a.d[i][j] += d[i][k]*m.d[k][j]%MOD) %= MOD;
		return a;
	}
	vector<T> operator*(const vector<T>& vec) const {
		vector<T> ret(N);
		rep(i,0,N) rep(j,0,N) (ret[i] += d[i][j] * vec[j] % MOD) %= MOD;
		return ret;
	}
	M operator^(ll p) const {
		assert(p >= 0);
		M a, b(*this);
		rep(i,0,N) a.d[i][i] = 1;
		while (p) {
			if (p&1) a = a*b;
			b = b*b;
			p >>= 1;
		}
		return a;
	}
};

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long r, c, lo, hi;
	cin >> r >> c >> lo >> hi;

	long long n = r*c;
	long long x = ((hi-(hi+1)%2) - (lo+(lo+1)%2)) / 2 + 1;
	long long y = hi-lo+1-x;

//	cerr << x << ' ' << y << '\n';
//	cerr << (hi-(hi+1)%2) << ' ' << (lo+(lo+1)%2) << '\n';


	Matrix<long long, 4> A;
	A.d = {{{{0LL,x,y,0LL}}, {{x,0LL,0LL,y}}, {{y,0LL,0LL,x}}, {{0LL,y,x,0LL}}}};

	vector<long long> vec = {0,0,0,1};
	vec = (A^n) * vec;

	cout << (vec[1]+vec[2]+vec[3])%MOD;
}


/*
 *
oo eo
oe ee

oo = oe * y + eo * x
eo = ee * y + oo * x
oe = oo * y + ee * x
ee = eo * y + oe * x
 *
 *
 */