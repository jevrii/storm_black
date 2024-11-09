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

#define MAXN 300005
#define MOD 998244353LL

void solve() {
	string s, ans;
	cin >> s;
	int cur = 0;
	for (char c : s) {
		int d = c - '0';
		if (cur > d) {
			ans += string(abs(cur-d), ')');
		}
		if (cur < d) {
			ans += string(abs(cur-d), '(');
		}
		cur = d;
		ans += string(1, c);
	}
	ans += string(cur, ')');

	cout << ans << '\n';
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	for (int no = 1; no <= t; no++) {
		cout << "Case #" << no << ": ";
		solve();
	}
}