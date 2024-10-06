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

int r, c;
vector<int> a[100005];
vector<int> elim[100005];


void solve() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		a[i].resize(c), elim[i].resize(c);

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> a[i][j];

	long long ans = 0;

	while (1) {
		vector<pii> vv;
		for (int x = 0; x < r; x++)
			for (int y = 0; y < c; y++) {
				vector<int> v;
				if (elim[x][y]) continue;
				ans += a[x][y];
				for (int dx = -1; dx; dx--) {
					if (x + dx < 0) break;
					if (not elim[x + dx][y]) {
						v.pb(a[x+dx][y]);
						break;
					}
				}

				for (int dx = +1; dx; dx++) {
					if (x + dx >= r) break;
					if (not elim[x + dx][y]) {
						v.pb(a[x+dx][y]);
						break;
					}
				}

				for (int dy = -1; dy; dy--) {
					if (y + dy < 0) break;
					if (not elim[x][y+dy]) {
						v.pb(a[x][y+dy]);
						break;
					}
				}

				for (int dy = +1; dy; dy++) {
					if (y + dy >= c) break;
					if (not elim[x][y+dy]) {
						v.pb(a[x][y+dy]);
						break;
					}
				}

				if (v.size() == 0) continue;
				if (a[x][y]*v.size() < accumulate(v.begin(), v.end(), 0)) {
					vv.pb(mp(x, y));
				}
			}

		if (not vv.size())
			break;
		for (auto op : vv) {
			elim[op.fi][op.se] = 1;
		}
	}

	cout << ans << '\n';


	for (int i = 0; i < r; i++)
		a[i].clear(), elim[i].clear();
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

//	init_pas();

	int t = 1; cin >> t;
	for (int no = 1; no <= t; no++) {
		cout << "Case #" << no << ": ";
		solve();
	}
}