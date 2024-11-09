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
#define MAXN 10004
//#define MOD 998244353LL
#define MOD 1000000007LL

int n;
int a[MAXN], dp[MAXN][4];

int sgn(int x) {
	if (x == 0) return 0;
	return x/abs(x);
}

void solve() {
	cin >> n;
	memset(dp, INF, sizeof(dp));
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i < 4; i++)
		dp[1][i] = 0;
	for (int i = 2; i <= n; i++) {
		for (int pre = 0; pre < 4; pre++)
			for (int cur = 0; cur < 4; cur++) {
				dp[i][cur] = min(dp[i][cur], dp[i-1][pre] + (sgn(cur-pre) != sgn(a[i]-a[i-1])));
			}
	}
	int ans = INF;
	for (int i = 0; i < 4; i++)
		ans = min(ans, dp[n][i]);
	cout << ans << '\n';
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