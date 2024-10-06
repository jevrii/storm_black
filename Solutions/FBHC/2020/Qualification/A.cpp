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
#define MAXN 55
//#define MOD 998244353LL
#define MOD 1000000007LL

int n;
bool ok[MAXN][MAXN]; // a to b ok?
bool reach[MAXN][MAXN];
bool vis[MAXN];

void dfs(int v, int src) {
	vis[v] = 1;
	reach[src][v] = 1;
	if (v >= 2 and ok[v][v-1] and not vis[v-1])
		dfs(v-1, src);

	if (v <= n-1 and ok[v][v+1] and not vis[v+1])
		dfs(v+1, src);
}

void solve() {
	cin >> n;

	memset(ok, 0, sizeof(ok));
	memset(reach, 0, sizeof(reach));

	for (int i = 1; i <= n; i++) {
		ok[i][i+1] = ok[i][i-1] = ok[i-1][i] = ok[i+1][i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		char in; cin >> in;
		if (in == 'N')
			ok[i-1][i] = ok[i+1][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		char out; cin >> out;
		if (out == 'N')
			ok[i][i-1] = ok[i][i+1] = 0;
	}

	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		dfs(i, i);
	}
	cout << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (reach[i][j] ? 'Y' : 'N');
		}
		cout << '\n';
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
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