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

#define MAXN 1005
#define MOD 998244353LL

long long d, m;
long long dp[40];
int max_bit;

long long work(int bit) {
	if (bit == max_bit) {
//		cerr << bit << ' ' << (d-(1<<bit) +1) << '\n';
		return d-(1<<bit) +1;
	}
	else {
//		cerr << bit << ' ' << ((1<<bit)) << '\n';
		return (1<<bit);
	}
}

long long dpf(int last_bit) {
	if (dp[last_bit] != -1)
		return dp[last_bit];
	if (last_bit == 0) {
		return 1;
	}
	long long ret = work(last_bit);
	for (int i = last_bit - 1; i >= 0; i--) {
		(ret += work(last_bit) * dpf(i) % m) %= m;
	}
	return dp[last_bit] = ret;
}

void solve() {
	cin >> d >> m;
	memset(dp, -1, sizeof(dp));
	max_bit = __lg(d);
	long long ans = 0;
	for (int i = 0; i <= max_bit; i++)
		(ans += dpf(i)) %= m;
	cout << ans << '\n';
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
}