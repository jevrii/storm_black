#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;

#define DEBUG 0
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 20004
//#define MOD 998244353LL
#define MOD 1000000007LL
bool vis[MAXN];

int n, m;
int n_asked = 0;
string secret = "_TFTFTFTTTFTFTTT";
vector<pair<int, char> > history[MAXN];

char ask(int b, int a) { // use b to test a.
	n_asked++;
#ifdef LOCAL
	if (secret[b] == 'T') {
		history[b].pb(mp(a, secret[a]));
		return secret[a];
	}
	else {
		char ans = "TF"[rand(0, 1)];
		history[b].pb(mp(a, ans));
		return ans;
	}
#else
	cout << 'T' << ' ' << b << ' ' << a << endl;
	fflush(stdout);
	char ans; cin >> ans;
	history[b].pb(mp(a, ans));
	return ans;
#endif
}

void solve() {
#ifdef LOCAL
	n = secret.length()-1;
	m = count(secret.begin(), secret.end(), 'T');
#else
	cin >> n >> m;
#endif
	vector<int> cur;
	for (int i = 1; i <= n; i++) {
		cur.pb(i);
	}

	int core = -1;

	while (cur.size() >= 2) {
//		test
//		shuffle(cur.begin(), cur.end(), rng);
		vector<int> nxt;
		for (int i = 0; i + 2 < cur.size(); i += 2) {
			char ans_a = ask(cur[i], cur[i+1]);
			char ans_b = ask(cur[i+1], cur[i]);
			if (ans_a == 'T' && ans_b == 'T') {
				nxt.pb(cur[i]);
			}
		}
		if (cur.size() % 2 == 1) { // odd length
			char ans_a = ask(cur[cur.size()-2], cur[cur.size()-1]);
			char ans_b = ask(cur[cur.size()-1], cur[cur.size()-2]);
			if (ans_a == 'T' && ans_b == 'T') {
				nxt.pb(cur[cur.size()-1]);
			}
		}
		if (nxt.size() == 0) { // no TT link. So must be TFTFT...T
			core = cur[0];
			for (int i = 0; i + 2 < cur.size(); i += 2) {
				history[core].pb(mp(cur[i], 'T'));
			}
			break;
		}
		cur = nxt;
	}

	cerr << "now asked " << n_asked << '\n';

	if (cur.size() == 2) { // TT
		core = cur[0];
		history[cur[0]].pb(mp(cur[1], 'T'));
		history[cur[1]].pb(mp(cur[0], 'T'));
	}
	else if (cur.size() == 1) {
		core = cur[0];
	}

	string ans(n+1, '?');
	set<int> s;
	for (int i = 1; i <= n; i++) s.insert(i);

	queue<int> q;
	int n_true = 0;
	q.push(core); vis[core] = 1; ans[core] = 'T';

	while (n_true < m) {
		while (q.size()) {
			int u = q.front(); q.pop();
			n_true++;
			s.erase(u);
//			cerr << "bfs " << u << '\n';
			for (auto op : history[u]) {
				int v; char state;
				tie(v, state) = op;
//				cerr << u << " ask " << v << ' ' << state << '\n';
				ans[v] = state;
				s.erase(v);
				if (state == 'T') {
					if (not vis[v]) {
						q.push(v);
						vis[v] = 1;
					}
				}
			}
		}
		while (s.size()) {
			int x = *s.begin();
			s.erase(s.begin());
			char state = ask(core, x);
			ans[x] = state;
			if (state == 'T') {
				q.push(x);
				vis[x] = 1;
				break;
			}
		}
	}

	cerr << ans.substr(1) << '\n';

	for (int i = 1; i <= n; i++) {
		if (ans[i] == '?') {
			ans[i] = 'F';
		}
	}

	cout << "R ";
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 'T') {
			cout << i << ' ';
		}
	}

//	cout << ans.substr(1) << '\n';
	cerr << "n_q: " << n_asked << '\n';
}

int main() {
#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
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