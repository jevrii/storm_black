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

vector<int> e[MAXN];
int n, cnt;
int bs;

void dfs(int v, int d = 0, int p = -1) {
	for (int u: e[v]) {
		if (u != p) {
			dfs(u, d + 1, v);
		}
		if (e[v].size() == 1) {
			bs |= (1 << (d % 2));
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
	}

	dfs(1);

	set<int> s;

	for (int i = 1; i <= n; i++) {
		if (e[i].size() == 1) {
			cnt++;
			s.insert(e[i][0]);
		}
	}

	cout << (__builtin_popcount(bs)==1?1:3) << ' ' << (n-cnt)-1+s.size() << '\n';
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	int t = 1;
//	cin >> t;
	for (int no = 1; no <= t; no++) {
//		cout << "Case #" << no << ": ";
		solve();
	}

}