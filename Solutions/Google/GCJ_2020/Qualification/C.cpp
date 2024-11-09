#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";
#define INF 0x3f3f3f3f3f3f3f3f

#define MAXN 1005
#define MOD 998244353LL

vector<int> e[MAXN];
int n, col[MAXN], vis[MAXN];
pii seg[MAXN];
bool bad;

void dfs(int v, int c = 0) {
	vis[v] = 1;
	col[v] = c;
	for (int u : e[v]) {
		if (col[u] == col[v]) {
			bad = 1;
		}
		if (not vis[u]) {
			dfs(u, c^1);
		}
	}
}

void solve() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> seg[i].fi >> seg[i].se;
		e[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			int l1, r1; tie(l1, r1) = seg[i];
			int l2, r2; tie(l2, r2) = seg[j];

			if (not (r1 <= l2 or r2 <= l1)) {
				e[i].pb(j);
				e[j].pb(i);
			}
		}
	}

	memset(vis, 0, sizeof(vis));
	memset(col, -1, sizeof(col));
	bad = 0;

	for (int v = 1; v <= n; v++) {
		if (not vis[v]) dfs(v);
	}

	if (bad) cout << "IMPOSSIBLE\n";
	else {
		for (int i = 1; i <= n; i++)
			cout << "CJ"[col[i]];
		cout << '\n';
	}


}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	for (int no = 1; no <= t; no++) {
		cout << "Case #" << no << ": ";
		solve();
	}
}