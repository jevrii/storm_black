#include <bits/stdc++.h>

#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 500005
//#define MOD 998244353LL
#define MOD 1000000007LL

int val[2005];
int n, q;

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n-1; i++)
		cin >> val[i];
	// between i and i+1

	while (q--) {
		int x, k;
		cin >> x >> k;
		if (k == 1) {
			cout << x << ' ';
			continue;
		}

		int l = x, r = x, la;

		for (int i = 0; i < k-1; i++) {
			if (r == n) l--, la=l;
			else if (l == 1) r++, la=r;
			else if (val[l-1] < val[r]) l--, la=l;
			else r++, la=r;
		}
		cout << la << ' ';
	}
	cout << '\n';
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	auto start_time = clock();
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;
	for (int no = 1; no <= t; no++) {
		cout << "Case #" << no << ": ";
		solve();
	}

#ifdef LOCAL
	cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}