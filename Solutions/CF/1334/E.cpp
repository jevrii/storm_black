#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 200005
#define MOD 998244353LL

vector<long long> pr;
map<long long, int> dp;

int dpf(long long x) {
	if (x == 1) return 1;
	if (dp.count(x)) return dp[x];
	int ret = 0;
	for (long long p : pr) {
		if (x%p) continue;
		(ret += dpf(x/p)) %= MOD;
	}
	return dp[x] = ret;
}

void solve() {
	long long d; cin >> d;
	for (long long i = 2; i*i <= d; i++) {
		if (d%i == 0) {
			pr.pb(i);
			while (d%i == 0) d/= i;
		}
	}
	if (d>1) pr.pb(d);

	int q; cin >> q;
	while (q--) {
		long long u, v;
		cin >> u >> v;
		long long g = __gcd(u, v);
		cout << (long long)dpf(u/g) * dpf(v/g) % MOD << '\n';
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
//	cin >> t;
	for (int no = 1; no <= t; no++) {
//		cout << "Case #" << no << ": ";
		solve();
	}

}