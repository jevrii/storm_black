#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

vector<int> d[105];
int n, m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int t[105];
        for (int j = 1; j <= n - 1; j++) cin >> t[j];
        int x; cin >> x;
        for (int j = 1; j <= n - 1; j++)
            d[j].pb(t[j] - x);
    }

    vector<int> ans (105, -1);

    for (int c = 1; c <= n - 1; c++) {
        vector<int> t;
        while (accumulate(d[c].begin(), d[c].end(), 0) < 0) {
            int pos = min_element(d[c].begin(), d[c].end()) - d[c].begin();
            t.pb(pos + 1);
            d[c][pos] = 0;
        }
        if (t.size() < ans.size()) ans = t;
    }

    cout << ans.size() << '\n';

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
    }

}
