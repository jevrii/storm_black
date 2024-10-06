#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

#define DEBUG 0
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 500005
#define MOD

int d[MAXN], a[MAXN], ps[MAXN];

void add(int l, int r, int val) {
    if (r<l) return;
    cerr << "add " << l << ' ' << r << ' ' << val << '\n';
    d[l]+=val;
    d[r+1]-=val;
}

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 2; i <= 2*k+5; i++)
        d[i] = 0;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n/2; i++) {
        test
        int x = a[i], y = a[n-1-i];

        add(x+y+1, max(x, y) + k, 1);
        add(max(x,y)+k+1, 2*k, 2);

        add(min(x,y)+1, x+y-1, 1);
        add(2, min(x,y), 2);
    }

    partial_sum(d, d+2*k+1, ps);

    cout << *min_element(ps+2, ps+2*k+1) << '\n';
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
//        cout << "Case #" << no << ": ";
        solve();
    }
}