#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define MAXN 100005

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, s = 0; cin >> n;
        bool odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s += x;
            if (x%2) odd = 1;
            else even = 1;
        }
        if (s%2) cout << "YES\n";
        else if (odd and even) cout << "YES\n";
        else cout << "NO\n";
    }

}
