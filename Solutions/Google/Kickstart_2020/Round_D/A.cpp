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
#define MAXN 200005
//#define MOD 998244353LL
#define MOD 1000000007LL

int n;
int a[MAXN];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mx = -1, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > mx && (i==n-1 || a[i] > a[i+1])) cnt++;
		mx = max(mx, a[i]);
	}
	cout << cnt << '\n';
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
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