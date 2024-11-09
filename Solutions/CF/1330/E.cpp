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

#define MAXN 5000006
#define MOD 998244353LL

int a[MAXN];
int h, g, n;
long long sum;

bool f(int i) {
//	cout << "call " << i << '\n';
	if (i >= (1<<h)) return 0;
	if (a[i] == 0) return 0;
	int lx = 2*i;
	int rx = 2*i+1;
	int prev = a[i];
	if (a[lx] == 0 and a[rx] == 0) {
		a[i] = 0;
	}
	else {
		if (a[lx] > a[rx]) {
			int old = a[lx];
			if (f(lx)) {
				a[i] = old;
			}
		}
		else {
			int old = a[rx];
			if (f(rx)) {
				a[i] = old;
			}
		}
	}
	if (i < (1 << g) and not a[i]) {
		a[i] = prev;
		return 0;
	}
	sum -= prev;
	sum += a[i];
	return a[i] != prev;
}

vector<int> ans;

void work(int v) {
	while (f(v)) {
		ans.pb(v);
//		for (int i = 1; i < n; i++) cout << a[i] << ' ';
//		cout << '\n';
	}
	if (2*v+1 < (1<<h))
		work(2*v+1);
	if (2*v < (1<<h))
		work(2*v);
}

void solve() {
	cin >> h >> g;
	n = (1<<h);
	sum = 0;

	for (int i = 1; i <= 2*n+3; i++)
		a[i] = 0;

	for (int i = 1; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}


//	int q; cin >> q;
//	while (q--) {
//		int x; cin >> x;
//		f(x);
//		for (int i = 1; i < n; i++) cout << a[i] << ' ';
//		cout << '\n';
//	}

	ans.clear();
	work(1);
	cout << sum << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " \n"[i+1==ans.size()];
//		assert(ans[i] < (1<<h));
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