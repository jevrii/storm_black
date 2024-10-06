#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

int dp[505][505], a[505][505];
int n, m, ans = 0;

void dfs(int x, int y, int bs = INT_MAX) {
	bs &= a[x][y];
	if (x == n and y == m) {
		ans = max(ans, bs);
		return;
	}
	if (x+1 <= n) {
		dfs(x+1, y, bs);
	}
	if (y+1 <= m) {
		dfs(x, y+1, bs);
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);

//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			cin >> a[i][j];
//
//	dp[1][1] = a[1][1];
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++) {
//			if (i == 1 and j == 1) continue;
//			dp[i][j] = max(dp[i-1][j] & a[i][j], dp[i][j-1] & a[i][j]);
//		}
//
//	cout << "fake ans " << dp[n][m] << '\n';
//	dfs(1, 1);
//	cout << "true ans " << ans << '\n';
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			cout << bitset<20>(a[i][j]).to_string() << ' ';
//		cout << '\n';
//	}

	int x; cin >> x;
	cout << "2 3\n";
	cout << 262143 << ' ' << x << ' ' << 0 << '\n';
	cout << "131072 262143 131071" << '\n';
//	262143 23 0
//	131072 262143 131071

}