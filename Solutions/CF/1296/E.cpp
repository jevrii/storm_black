#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
#define INF 0x3f3f3f3f

#define MAXN 200005

int n;
int T[MAXN], a[MAXN];

int ask(int x) {
    int ret = 0;
    for (x++; x; x -= x&-x) {
        ret = max(ret, T[x]);
    }
    return ret;
}

void upd(int x, int val) {
    for (x++; x < MAXN; x += x&-x) {
        T[x] = max(T[x], val);
    }
}

void solve() {
    string s;
    cin >> n >> s;

    vector<int> ord;
    vector<int> countingSort[26];
    for (int i = n-1; i >= 0; i--) {
        countingSort[s[i]-'a'].pb(i);
    }
    for (int i = 25; i >= 0; i--) {
        for (int x : countingSort[i])
            ord.pb(x);
    }


    int ans = 0;

    for (int x : ord) {
        a[x] = ask(x) + 1;
        upd(x, a[x]);
        ans = max(ans, a[x]);
    }

    cout << ans << '\n';
    for (int i = 0; i < n; i++)
        cout << a[i] << (i+1==n ? '\n' : ' ');
}

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

//    cout << 200000 << '\n';
//    for (int i = 0; i < 200000; i++) {
//        cout << (char)('a'+rand()%26);
//    }

}
