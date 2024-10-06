#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define MAXN 100005

void solve() {
    int n; cin >> n;
    long long ans = 0;
    while (n >= 10) {
        ans += n-n%10;
        n = n%10 + n/10;
    }
    cout << ans + n << '\n';
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
