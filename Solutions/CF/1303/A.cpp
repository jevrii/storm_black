#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define MAXN 200005
#define INF 0x3f3f3f3f
#define MOD 1000000007LL

void solve() {
    int st = -1, ed = -1, cnt = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            if (st == -1) st = i;
            ed = i;
            cnt++;
        }
    }
    if (cnt == 0) cout << 0 << '\n';
    else {
        cout << (ed-st+1)-cnt << '\n';
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif

    int t; cin >> t;
    while (t--)
        solve();

}
