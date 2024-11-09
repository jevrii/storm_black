#include <bits/stdc++.h>

#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 1000006
//#define MOD 998244353LL
#define MOD 1000000007LL

#define RIGHT 0
#define LEFT 1
#define STAND 2

map<long long, long long> m, fall_to_right, fall_to_left;
int n;



void solve() {
	cin >> n;
	m.clear();
	fall_to_left.clear();
	fall_to_right.clear();
	for (int i = 1; i <= n; i++) {
		long long p, h; cin >> p >> h;
		m[p] = h;
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		long long p, h; tie(p, h) = *it;
		fall_to_right[p+h] = max(fall_to_right[p+h], (fall_to_right.count(p) ? fall_to_right[p] : 0) + h);
	}

	for (auto it = m.rbegin(); it != m.rend(); it++) {
		long long p, h; tie(p, h) = *it;
		fall_to_left[p-h] = max(fall_to_left[p-h], (fall_to_left.count(p) ? fall_to_left[p] : 0) + h);
	}

	long long ans = 0;
	for (auto op : fall_to_right) {
		ans = max(ans, op.se + (fall_to_left.count(op.fi) ? fall_to_left[op.fi] : 0));
	}
	for (auto op : fall_to_left) {
		ans = max(ans, op.se + (fall_to_right.count(op.fi) ? fall_to_right[op.fi] : 0));
	}
	cout << ans << '\n';

}

int main() {
#ifdef LOCAL
	freopen("timber_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	auto start_time = clock();
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;
	for (int no = 1; no <= t; no++) {
		cout << "Case #" << no << ": ";
		solve();
	}

#ifdef LOCAL
	cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}