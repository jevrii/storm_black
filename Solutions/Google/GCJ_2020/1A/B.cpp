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

long long sum = 0;
long long pas[505][505];

//void move(int x, int y) {
//	cout << x+1 << ' ' << y+1 << '\n';
//	sum += pas[x][y];
//}

void init_pas() {
	for (int i = 0; i < 505; i++) { // pas[n][r] stores C(n, r)
		pas[i][0] = pas[i][i] = 1;
		for (int j = 1; j < i; j++) {
			pas[i][j] = (pas[i - 1][j] + pas[i - 1][j - 1]);
		}
	}
}

void solve() {
	int n; cin >> n;

	vector<int> bits = {0};
//	for (int i = 1, x; i < n; i++) {
//		cin >> x;
//		bits.pb(x);
//	}
	for (int i = 1; i <= 30; i++)
		if (n & (1 << i)) bits.pb(i);

	vector<pii> ans;
	int N = 0, R = 0;

	for (int i = 0, d = 1; i < bits.size(); i++, d *= -1) {
		for (int j = R; 0 <= j && j <= N; j += d)
			ans.pb(mp(N, j)), R = j;

		if (i+1 == bits.size()) break;

		int skip = bits[i+1]-bits[i]-1;

		if (skip == 0) {
			if (R == N) R++;
			N++;
		}
		else {
			if (R == N) R++;
			N++;
			bool on_right = (d == 1);
//			cerr << "pyramid " << bits[i] << ' ' << skip << ' ' << N << ' ' << R << ' ' << on_right << '\n';
			if (skip%2 == 1) d *= -1;
			for (int i = 1; i <= skip; i++, d *= -1) {
				if (on_right) {
					for (int j = R; N-i+1 <= j && j <= N; j += d)
						ans.pb(mp(N, j)), R = j;
				}
				else {
					for (int j = R; 0 <= j && j < i; j += d)
						ans.pb(mp(N, j)), R = j;
				}

				if (d == 1) R++;
				N++;
			}
		}
	}

	if (n % 2 == 0)
		ans.pop_back();

	cout << '\n';

	for (auto op : ans) {
		cout << op.fi+1 << ' ' << op.se+1 << ' ' << '\n';
		sum += pas[op.fi][op.se];
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	init_pas();

	int t = 1; cin >> t;
	for (int no = 1; no <= t; no++) {
		cout << "Case #" << no << ": ";
		solve();
	}
}