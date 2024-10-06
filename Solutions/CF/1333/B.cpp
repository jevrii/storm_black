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

#define MAXN 500005
#define MOD 998244353LL

int a[MAXN], b[MAXN];
int n;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	for (int i = 0, got_add = 0, got_dec = 0; i < n; i++) {
		if (a[i] < b[i]) {
			if (not got_add) {
				cout << "NO\n";
				return;
			}
		}
		if (a[i] > b[i]) {
			if (not got_dec) {
				cout << "NO\n";
				return;
			}
		}

		if (a[i] == 1) got_add = 1;
		if (a[i] == -1) got_dec = 1;
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