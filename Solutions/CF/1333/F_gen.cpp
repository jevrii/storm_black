#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";
#define INF 0x3f3f3f3f3f3f3f3f

#define MAXN 500005
#define MOD 998244353LL

pii ans[MAXN];

void solve() {
	int n = 20;
	for (int i = 1; i <= n; i++)
		ans[i].fi = INF;
	for (int bs = 1; bs < (1 << n); bs++) {
		vector<int> v;
		for (int i = 0; i < n; i++) {
			if (bs & (1 << i)) {
				v.pb(i+1);
			}
		}
		int val = 0;
		for (int x : v)
			for (int y : v) {
				if (x != y) {
					val = max(val, __gcd(x, y));
				}
			}
		int cnt = __builtin_popcount(bs);
		ans[cnt] = min(ans[cnt], mp(val, bs));
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i].fi << ' ' << bitset<20>(ans[i].se) << ": ";
		for (int j = 0; j < n; j++) {
			if (ans[i].se & (1 << j)) {
				cout << j+1 << ' ';
			}
		}
		cout << '\n';
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}