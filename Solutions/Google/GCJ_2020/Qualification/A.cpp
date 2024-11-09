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

int a[105][105];
int n;

void solve() {
	cin >> n;
	int tr = 0, rr = 0, rc = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (i == j) tr += a[i][j];
		}



	for (int r = 1; r <= n; r++) {
		set<int> s;
		for (int c = 1; c <= n; c++) {
			s.insert(a[r][c]);
		}
		rr += (s.size() < n);
	}

	for (int c = 1; c <= n; c++) {
		set<int> s;
		for (int r = 1; r <= n; r++) {
			s.insert(a[r][c]);
		}
		rc += (s.size() < n);
	}

	cout << tr << ' ' << rr << ' ' << rc << '\n';

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