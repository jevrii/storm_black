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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i< n; i++) cin >> a[i];
	int mx = a[0];
	int ans = 0;
	for (int i = 1; i < n; i++) {
		int d = max(0, mx-a[i]);
		if (d)
			ans = max(ans, __lg(d)+1);
		mx = max(mx, a[i]);
	}
	cout << ans << '\n';
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	int t = 1;
	cin >> t;
	for (int no = 1; no <= t; no++) {
//		cout << "Case #" << no << ": ";
		solve();
	}

}