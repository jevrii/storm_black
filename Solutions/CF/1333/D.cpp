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

int n, k;
string s;
vector<vector<int> > ans;
vector<vector<int> > vv;

int cur;

void solve() {
	cin >> n >> k >> s;
	for (char &c:s) {
		if (c == 'L') c = '<';
		if (c == 'R') c = '>';
	}

	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++) {
			if (s[i] == '>' and s[j] == '<') cur++;
		}

	if (cur < k) {
		cout << -1 << '\n';
		return;
	}

	vector<int> swaps;
	for (int i = 0; i+1 < n; i++) {
		if (s[i] == '>' && s[i+1] == '<') {
			swaps.pb(i);
		}
	}

	while (swaps.size()) {
		vv.pb(swaps);
		vector<int> s2;
		for (int x : swaps) {
			swap(s[x], s[x+1]);
			if (x-1>=0 and s[x-1] == '>' and s[x] == '<') s2.pb(x-1);
			if (x+2<n and s[x+1] == '>' and s[x+2] == '<') s2.pb(x+1);
		}
		swap(s2, swaps);
	}

	if (k < vv.size()) {
		cout << -1 << '\n';
		return;
	}

	int split = k - vv.size();

	for (auto v : vv) {
		if (v.size() == 1) ans.pb(v);
		else {
			while (split and v.size() > 1) {
				ans.pb({v.back()});
				v.pop_back();
				split--;
			}
			ans.pb(v);
		}
	}

	for (auto v : ans) {
		cout << v.size() << ' ';
		for (int x : v) cout << x+1 << ' ';
		cout << '\n';
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}