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
#define MAXN 200005
#define MOD 998244353LL

void solve() {
	map<int, int> m;
	int n;
	int mx = 0;
	cin >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		m[x]++;
		mx = max(mx, m[x]);
	}
	cout << max(min(mx, (int)m.size()-1), min(mx-1, (int)m.size())) << '\n';
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
	}

}