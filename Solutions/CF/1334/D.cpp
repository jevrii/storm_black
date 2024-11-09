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

long long print_l, print_r, n;
long long cur = 1;
vector<int> ans;

void move_range(int st, int lo, int hi) {
//	cerr << "call  " << st << ' ' << lo << ' ' << hi << '\n';
	long long len = hi-lo+1; len *= 2;
	if (not (cur+len-1 < print_l or cur > print_r)) {
		for (long long i = 0, x, c = lo; i < len; i++) {
			if (i%2 == 0) {
				x = c++;
			}
			else {
				x = st;
			}
			if (print_l <= cur and cur <= print_r) {
				ans.pb(x);
			}
			cur++;
		}
	}
	else {
		cur += len;
	}
}

void move_once(long long x) {
	if (print_l <= cur and cur <= print_r) {
		ans.pb(x);
	}
	cur++;
}

void solve() {
	cin >> n >> print_l >> print_r;
	cur = 1;
	ans.clear();

	for (long long st = 1; st < n; st++) {
		if (st == n-1) {
			move_once(st);
			move_once(n);
			move_once(1);
		}
		else {
			move_once(st);
			move_range(st, st + 1, n-1);
			move_once(n);
		}
	}
	for (long long x : ans) cout << x << ' ';
	cout << '\n';
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