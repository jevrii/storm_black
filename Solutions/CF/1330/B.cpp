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

#define MAXN 200005
#define MOD 998244353LL

int a[MAXN], n;
int ok[MAXN][2];
set<int> s;

void solve() {
	multiset<int> pre, suf;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ok[i][0] = ok[i][1] = 0;
	}

	s.clear();
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		if (s.count(x)) break;
		s.insert(x);
		if (*s.begin() == 1 && *s.rbegin() == i)
			ok[i][0] = 1;
	}

	s.clear();
	for (int i = n, len = 1; i >= 1; i--, len++) {
		int x = a[i];
		if (s.count(x)) break;
		s.insert(x);
		if (*s.begin() == 1 && *s.rbegin() == len)
			ok[i][1] = 1;
	}

	vector<pii> ans;
	for (int i = 1; i+1 <= n; i++) {
		if (ok[i][0] && ok[i+1][1]) {
			ans.pb(mp(i, n-i));
		}
	}

	cout << ans.size() << '\n';
	for (auto op : ans) {
		cout << op.fi << ' ' << op.se << '\n';
	}

}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
}