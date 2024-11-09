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

#define MAXN 500005
#define MOD 998244353LL

long long a[MAXN];
vector<int> e[MAXN];
int n, m;
bool done[MAXN];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		done[i] = 0;
		e[i].clear();
	}

	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		e[u].pb(v);
	}
	long long g = 0;

	vector<int> v(n);
	iota(v.begin(), v.end(), 1);

	for (int iter = 0; iter < 10; iter++) {
		random_shuffle(v.begin(), v.end());

		for (int i : v) {
			if (not e[i].size()) continue;
			long long s = 0;
			for (int u : e[i])
				s += a[u];
			g = __gcd(g, s);

			s = 0;
			for (int u : e[i]) {
				if (not done[u]) {
					s += a[u];
				}
				done[u] = 1;
			}
			g = __gcd(g, s);
		}
	}
	cout << g << '\n';
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