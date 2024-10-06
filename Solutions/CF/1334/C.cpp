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
#define MAXN 500005
#define MOD 998244353LL

int n;
long long a[MAXN], b[MAXN], cost[MAXN];
int reach[MAXN];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	for (int i = 0; i < n; i++) {
		cost[i] = max(0LL, a[i] - b[(i-1+n)%n]);
	}

	long long sum = accumulate(cost, cost+n, 0LL);

	long long ans = 4e18;
	for (int i = 0; i < n; i++) {
		ans = min(ans, a[i] + sum - cost[i]);
	}

	cout << ans << '\n';
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
}