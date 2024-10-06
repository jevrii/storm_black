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

#define MAXN 100005
#define MOD 998244353LL

void solve() {
	set<int> s;
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		s.insert(a);
	}
	int cnt, ans;
	for (ans = 1, cnt = 0; cnt < x; ans++) {
		if (!s.count(ans)) {
			s.insert(ans);
			cnt++;
		}
	}
	for (int i = 1; i <= 1e9; i++) {
		if (!s.count(i)) {
			cout << i-1 << '\n';
			return;
		}
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