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
#define MAXN 1000006
#define MOD 998244353LL

int r, c;
string str_col[MAXN];
string str_dir[MAXN];
vector<int> e[MAXN], rev[MAXN];
int col[MAXN], vis[MAXN], vis2[MAXN];
int cyc_len, black_cnt;

inline int id(int x, int y) {
	return c*x + y;
}

vector<int> st;
int got[MAXN];

void dfs2(int v, int mod, int d = 0) {
	cerr << "vis2 " << v << ' ' << col[v] << '\n';
	vis2[v] = 1;
	got[d] |= col[v];
	for (int u : rev[v]) {
		if (not vis2[u]) dfs2(u, mod, (d+1)%mod);
	}
}

void dfs(int v) {
	if (vis[v] or vis2[v]) return;
	cerr << "dfs " << v << '\n';
	vis[v] = 1;
	st.pb(v);
	for (int u : e[v]) {
		if (not vis[u])
			dfs(u);
		else {
			int cyc = st.end() - find(st.begin(), st.end(), u);
			if (cyc == 0) continue;
			fill(got, got + cyc, 0);
			cerr << "call cyc " << v << ' ' << u << '\n';
			dfs2(u, cyc);

			black_cnt += accumulate(got, got+cyc, 0);
			cyc_len += cyc;
		}
	}
	st.pop_back();
}

void solve() {
	cin >> r >> c;

	for (int i = 0; i < r; i++)
		cin >> str_col[i];
	for (int i = 0; i < r; i++)
		cin >> str_dir[i];

	for (int x = 0; x < r; x++)
		for (int y = 0; y < c; y++) {
			int nx = x, ny = y;
			if (str_dir[x][y] == 'U') nx--;
			if (str_dir[x][y] == 'D') nx++;
			if (str_dir[x][y] == 'L') ny--;
			if (str_dir[x][y] == 'R') ny++;

			e[id(x, y)].pb(id(nx, ny));
			rev[id(nx, ny)].pb(id(x, y));
			cerr << "rev " << id(nx, ny) << ' ' << id(x, y) << '\n';

			col[id(x, y)] = str_col[x][y]=='0';
		}

	int n = r*c;

	for (int i = 0; i < n; i++) {
		if (not vis[i] and not vis2[i]) {
			cerr << "call dfs " << i << '\n';
			dfs(i);
		}
	}

	cout << cyc_len << ' ' << black_cnt << '\n';
}

void reset() {
	for (int i = 0; i < r*c; i++) {
		e[i].clear();
		rev[i].clear();
		vis[i] = vis2[i] = cyc_len = black_cnt = 0;
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;
	for (int no = 1; no <= t; no++) {
//		cout << "Case #" << no << ": ";
		solve();
		reset();
	}

}