#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

long long l[15];
map<int, int> cnt;
int n;
bool ok[2000006];
int sum[2000006];
int mx = 1e9;

void work(int k) {
    for (int s = 1; s <= k; s++) {
        if (k % s == 0 || k/s + k%s >= s-1) sum[s] += k/s + !!(k%s);
        else ok[s] = 0;
    }
    sum[k+1]++;
    mx = min(mx, k+1);
}

void solve() {
    cin >> n;
    cnt.clear();
    for (int i = 0; i <= n; i++) ok[i] = 1, sum[i] = 0;
    mx = 1e9;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    for (auto op : cnt) {
        work(op.se);
    }
    int ans = 1e9;
    for (int i = 1; i <= mx; i++) {
        if (ok[i]) ans = min(ans, sum[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

}
