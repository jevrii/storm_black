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

vector<int> pre[205], suf[205];
int ps[205][200005];
int n, a[MAXN], ans;

void solve() {
	cin >> n;

	ans = 0;
	for (int i = 1; i <= 200; i++) {
		pre[i].clear();
		suf[i].clear();
	}

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
		pre[a[i]].pb(i);

	for (int i = n; i >= 1; i--)
		suf[a[i]].pb(i);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 200; j++) {
			ps[j][i] = ps[j][i-1];
		}
		ps[a[i]][i]++;
	}

	for (int ch = 1; ch <= 200; ch++) {
		ans = max(ans, (int)pre[ch].size());
		for (int len = 0; len < pre[ch].size(); len++) {
			if (pre[ch][len] >= suf[ch][len]) break;

			for (int mi = 1; mi <= 200; mi++) {
				ans = max(ans, (len+1)*2 + ps[mi][suf[ch][len]-1] - ps[mi][pre[ch][len]]);
			}
		}
	}

	cout << ans << '\n';


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