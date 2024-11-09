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

string s[9];

void solve() {
	for (int i = 0; i < 9; i++)
		cin >> s[i];

	for (int i = 0; i < 3; i++) {
		s[0+i][0+i*3] = s[0+i][1+i*3];
		s[3+i][1+i*3] = s[3+i][2+i*3];
		s[6+i][2+i*3] = s[6+i][1+i*3];
	}

	for (int i = 0; i < 9; i++)
		cout << s[i] << '\n';


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