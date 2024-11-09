#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define MAXN 200005
#define INF 0x3f3f3f3f3f3f3f3f
map<char, int> cnt[MAXN];

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	for (int i = 0; i < n; i++)
		cnt[i].clear();
	for (int i = 0; i < n; i++) {
		cnt[i%k][s[i]]++;
//		cerr << "count " << i%k << ' ' << s[i] << '\n';
	}

	int ans = 0;
	for (int lx = 0, rx = k-1; lx <= rx; lx++, rx--) {
		if (lx == rx) {
			int mx = INF;
			for (auto op : cnt[lx]) {
				mx = min(mx, n/k-op.se);
			}
			ans += mx;
		}
		else {
			int mx = INF;
			for (char c = 'a';  c <= 'z'; c++) {
				int cl, cr;
				if (!cnt[lx].count(c)) cl = 0;
				else cl = cnt[lx][c];

				if (!cnt[rx].count(c)) cr = 0;
				else cr = cnt[rx][c];

//				cerr << lx << ' ' << rx << ' ' << c << ' ' << 2*n/k-cl-cr << '\n';

				mx = min(mx, 2*n/k-cl-cr);
			}
			ans += mx;
		}
	}
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