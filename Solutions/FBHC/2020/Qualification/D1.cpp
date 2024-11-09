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
#define MAXN 1000006
//#define MOD 998244353LL
#define MOD 1000000007LL

int n, m;
long long c[MAXN];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	deque<pair<long long, int> > q;
	q.push_back(mp(0LL, 1));
	for (int i = 2; i <= m; i++) {
		if (c[i]) {
			while (q.size() && q.back().fi > c[i])
				q.pop_back();
			q.push_back(mp(c[i], i));
		}
	}
	for (int i = m+1; i <= n; i++) {
		while (q.size() && q.front().se < i-m)
			q.pop_front();
		if (c[i]) {
			if (q.size() == 0)
				continue;
			long long cur_cost = c[i] + q.front().fi;
			while (q.size() && q.back().fi > cur_cost)
				q.pop_back();
			q.push_back(mp(cur_cost, i));
		}
	}
	long long ans = INF;
	for (auto op : q) {
		if (op.se >= n-m) {
			ans = min(ans, op.fi);
		}
	}
	if (ans == INF) cout << -1 << '\n';
	else cout << ans << '\n';
}

int main() {
#ifdef LOCAL
	freopen("running_on_fumes_chapter_1_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
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