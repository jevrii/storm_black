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
#define MAXN 500005
#define MOD 998244353LL

set<int> s;

void solve() {
	for (int iter = 0; iter < 1000; iter++) {
		for (int i = 1; i <= 2000; i++) {
			if (s.count(i)) continue;
			for (int j = i+1; j <= 2000; j++) {
				if (s.count(j)) continue;
				for (int k = j+1; k <= 2000; k++) {
					if (s.count(k)) continue;
					if ((i^j^k) == 0) {
						s.insert(i);
						s.insert(j);
						s.insert(k);

//						if (i*2 == j && i*3 == k) {
//							cout << "triple\n";
//						}
//						cout << __builtin_popcount(i&j) << '\n';

						cout << bitset<10>(i) << ' ' << iter << '\n';
//						cout << j << ',' << '\n';
//						if (iter % 16 == 0)
//						cout << bitset<10>(k) << ' ' <<>'\n';
//						cout << '\n';

						goto end;
					}
				}
			}
		}
		break;
		end:;
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	int t = 1;
//	cin >> t;
	for (int no = 1; no <= t; no++) {
//		cout << "Case #" << no << ": ";
		solve();
	}

}