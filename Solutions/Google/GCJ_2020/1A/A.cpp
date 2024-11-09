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

bool is_pref(string s, string t) {
	if (t.length() < s.length()) return 0;
	return t.substr(0, s.length()) == s;
}

void solve() {
	int n; cin >> n;
	vector<string> pref, suff, whole;
	string sub;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		string st, ed;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '*') break;
			st += string(1, s[i]);
		}

		for (int i = s.length()-1; i >= 0; i--) {
			if (s[i] == '*') break;
			ed += string(1, s[i]);
		}

		if (st.length() == s.length()) {
			whole.pb(st);
		}
		else {
			if (st.length()) {
				pref.pb(st);
			}

			if (ed.length()) {
				suff.pb(ed);
			}
			string ss;
			for (int i = st.length(); i < s.length()-ed.length(); i++) {
				if (s[i] != '*')
					ss += string(1, s[i]);
			}
			sub += ss;
		}
	}

	sort(pref.begin(), pref.end());
	sort(suff.begin(), suff.end());

	for (int i = 0; i+1 < pref.size(); i++) {
		if (!is_pref(pref[i], pref[i+1])) {
			cout << "*\n";
			return;
		}
	}

	for (int i = 0; i+1 < suff.size(); i++) {
		if (!is_pref(suff[i], suff[i+1])) {
			cout << "*\n";
			return;
		}
	}
	if (suff.size()) reverse(suff.back().begin(), suff.back().end());
	string ans = (pref.size()?pref.back():"") + sub + (suff.size()?suff.back():"");

	cout << ans << '\n';
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int no = 1; no <= t; no++) {
		cout << "Case #" << no << ": ";
		solve();
	}
//	while (t--) {
//		solve();
//	}

}