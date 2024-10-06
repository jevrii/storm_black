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

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	for (int i = 0; i < b-1; i++)
		s += string(1, 'a'+i);
	s += string(a-(b-1), 'a'+b-1);
	for (int i = 0; i < n; i++) {
		cout << s[i%s.length()];
	}
	cout << '\n';
//	cout << s << '\n';
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