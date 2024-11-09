#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define MAXN 100005
#define INF 0x3f3f3f3f3f3f3f3f

vector<int> pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void solve() {
	int n; cin >> n;
	vector<int> ans;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int j = 0; j < 11; j++) {
			if (x % pr[j] == 0) {
				ans.pb(j+1);
				s.insert(j+1);
				break;
			}
		}
	}
	vector<int> vals(s.begin(), s.end());
	cout << s.size() << '\n';
	for (int i = 0; i < n; i++) cout << lower_bound(vals.begin(), vals.end(), ans[i])-vals.begin() + 1 << " \n"[i+1==n];
}


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

}