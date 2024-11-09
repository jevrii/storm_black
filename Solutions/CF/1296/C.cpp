#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define MAXN 100005
#define INF 0x3f3f3f3f

void solve() {
    int n;
    string s;
    cin >> n >> s;

    map<pii, vector<int>> m;
    m[{0, 0}].pb(0);

    for (int i = 0, x = 0, y = 0; i < n; i++) {
        char c = s[i];
        if (c == 'U') y++;
        if (c == 'D') y--;
        if (c == 'L') x--;
        if (c == 'R') x++;

        m[{x, y}].pb(i + 1);
    }

    pair<int, pii> ans;
    ans.fi = INF;
    for (auto& op : m) {
        vector<int>& v = op.se;
        for (int i = 0; i+1 < v.size(); i++) {
            ans = min(ans, mp(v[i+1]-v[i], mp(v[i]+1,v[i+1])));
        }
    }
    if (ans.fi == INF) cout << -1 << '\n';
    else cout << ans.se.fi << ' ' << ans.se.se << '\n';

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
