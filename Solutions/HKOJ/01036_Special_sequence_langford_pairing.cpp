// https://susam.in/blog/langford-pairing/

#include <bits/stdc++.h>

#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 1000006
//#define MOD 998244353LL
#define MOD 1000000007LL

vector<int> rev(vector<int> v) {
	reverse(v.begin(), v.end());
	return v;
}

void print(vector<vector<int> > vs) {
	for (auto v : vs)
		for (int x : v)
			cout << x << ' ';
}

void solve() {
	int n; cin >> n;
	int x = (n+3)/4;
	vector<int> a = {2*x-1};
	vector<int> b = {4*x-2};
	vector<int> c = {4*x-1};
	vector<int> d = {4*x};
	vector<int> p, q, r, s;
	for (int i = 1; i < a[0]; i++) {
		if (i % 2 == 0) q.pb(i);
		else p.pb(i);
	}
	for (int i = a[0]+1; i < b[0]; i++) {
		if (i % 2 == 0) s.pb(i);
		else r.pb(i);
	}

	if (n % 4 == 0)
		print({rev(s), rev(p), b, p, c, s, d, rev(r), rev(q), b, a, q, c, r, a, d});
	else if (n % 4 == 3)
		print({rev(s), rev(p), b, p, c, s, a, rev(r), rev(q), b, a, q, c, r});
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	auto start_time = clock();
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
//    cin >> t;
	for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
		solve();
	}

#ifdef LOCAL
	cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}