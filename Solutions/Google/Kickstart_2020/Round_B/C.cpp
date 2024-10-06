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
#define MAXN 200005
//#define MOD 998244353LL
#define MOD 1000000000LL

void solve() {
    string s;
    cin >> s;
    vector<pair<int, pii> > v;
    s = "1(" + s + ")";

    for (int i = 0; i < s.length()-1; i++) {
        if (isdigit(s[i])) {
            v.pb(mp(s[i]-'0', mp(0, 0)));
        }
        else if (isupper(s[i])) {
            if (s[i] == 'N') v.back().se.se--;
            if (s[i] == 'S') v.back().se.se++;
            if (s[i] == 'E') v.back().se.fi++;
            if (s[i] == 'W') v.back().se.fi--;
        }
        else if (s[i] == ')') {
            pii tot = v.back().se;
            tot.fi *= v.back().fi;
            tot.se *= v.back().fi;
            tot.fi %= MOD;
            tot.se %= MOD;
            v.pop_back();
            (v.back().se.fi += tot.fi)%=MOD;
            (v.back().se.se += tot.se)%=MOD;
        }
    }

    int x, y;
    tie(x, y) = v.back().se;
    cout << (x%MOD+MOD)%MOD+1 << ' ' << (y%MOD+MOD)%MOD+1 << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for (int no = 1; no <= t; no++) {
        cout << "Case #" << no << ": ";
        solve();
    }

}