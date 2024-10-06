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

int p[MAXN], c[MAXN], n;

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i] >> c[i];

	for (int i = 0; i+1 <= n; i++) {
		int dp = p[i+1]-p[i];
		int dc = c[i+1]-c[i];
		if (dp<0 || dc<0 || dc>dp) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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