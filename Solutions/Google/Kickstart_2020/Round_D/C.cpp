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

vector<int> e[MAXN];
int n, a, b, d[MAXN];
long double ans;
unordered_map<int, int> m[MAXN];
long double cnt[2][MAXN];
int mod, pp;

void dfs1(int v, int dep=0) {
	d[v] = dep;
	for (int u : e[v])
		dfs1(u, dep+1);
}

void dfs(int v) {
	if (e[v].size()) {
		pii max_size = {-1, -1};
		for (int u : e[v]) {
			dfs(u);
			max_size = max(max_size, mp((int)m[u].size(), u));
		}
		swap(m[v], m[max_size.se]);
		for (int u : e[v]) {
			if (u == max_size.se) continue;
			for (auto op : m[u]) {
				m[v][op.fi % mod] += op.se;
			}
		}

		for (int u : e[v])
			m[u].clear();
	}
	m[v][d[v]%mod]++;

	cnt[pp][v] = m[v][d[v]%mod];
}

void solve() {
	cin >> n >> a >> b;
	ans = 0;
	for (int i = 1; i <= n; i++) e[i].clear(), m[i].clear();

	for (int i = 2; i <= n; i++) {
		int p; cin >> p;
		e[p].pb(i);
	}

	dfs1(1); // precompute depth
	mod=a; pp=0; dfs(1);
	mod=b; pp=1; dfs(1);

	for (int i = 1; i <= n; i++)
		ans += 1.0 - ((1.0-cnt[0][i]/n) * (1.0-cnt[1][i]/n));

	cout << fixed << setprecision(12) << ans << '\n';
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