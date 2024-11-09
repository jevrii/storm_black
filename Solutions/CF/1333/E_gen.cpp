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
#define INF 0x3f3f3f3f

#define MAXN 500005
#define MOD 998244353LL

int a[3][3];
int vis[3][3];

int walk(bool rook) {
	int x, y, cnt = 0;
	memset(vis, 0, sizeof(vis));

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (a[i][j] == 1) {
				x = i, y = j;
			}

	for (int i = 0; i < 8; i++) {
		vis[x][y] = 1;
//		cerr << "pos " << x << ' ' << y << '\n';
		pair<int, pii> nxt;
		nxt.fi = INF;
		for (int dx = -3; dx <= 3; dx++) {
			for (int dy = -3; dy <= 3; dy++) {
				if (dx == 0 and dy == 0) continue;
				if (rook and not (dx == 0 or dy == 0)) continue;
				if (x+dx<0 or y+dy <0 or x+dx>2 or y+dy>2) continue;
				if (not rook and not (dx == 0 or dy == 0 or (abs(dx) == abs(dy)))) continue;
				if (vis[x+dx][y+dy]) continue;
//				cerr << "upd " << x+dx << ' ' << y+dy << '\n';
				nxt = min(nxt, mp(a[x+dx][y+dy], mp(x+dx, y+dy)));
			}
		}
		if (nxt.fi == INF) {
			cnt++;
//			cerr << "bad!\n";
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++) {
					if (not vis[i][j]) {
						nxt = min(nxt, mp(a[i][j], mp(i, j)));
					}
				}
		}
		tie(x, y) = nxt.se;
	}

	return cnt;
}

void solve() {
	int p[] = {1,2,3,4,5,6,7,8,9};

	do {
		for (int i = 0; i < 9; i++) {
			a[i/3][i%3] = p[i];
		}
//		int x = walk(1);
//		int y = walk(0);
//		cerr << x << ' ' << y << '\n';

		if (walk(1) < walk(0)) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					cout << a[i][j] << ' ';
				cout << '\n';
			}
			exit(0);
		}
	} while (next_permutation(p, p + 9));
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