#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

string s;
vector<pair<char, pii> > v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    int n = s.length();
    v.pb(mp(s[0], mp(0, n)));
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1])
            v.back().se.se = i, v.pb(mp(s[i], mp(i, n)));
    }
    if (v.size() % 2 == 0) {
        cout << "0\n";
    }
    else if (v[v.size()/2].se.se-v[v.size()/2].se.fi + 1 < 3){
        cout << "0\n";
    }
    else {
        for (int l = v.size()/2-1, r = v.size()/2+1; l>=0; l--, r++) {
            int l1 = v[l].se.se - v[l].se.fi;
            int l2 = v[r].se.se - v[r].se.fi;
            if (v[l].fi != v[r].fi || l1 + l2  < 3) {
                cout << 0 << '\n';
                return 0;
            }
        }
        cout << v[v.size() / 2].se.se - v[v.size()/2].se.fi + 1 << '\n';
    }
}
