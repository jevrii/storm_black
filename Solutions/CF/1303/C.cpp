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
    string s; cin >> s;
    deque<char> q;
    bool used[255] = {0};
    q.push_back(s[0]);
    used[s[0]] = 1;

    for (int i = 1, cur = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == q[cur]) continue;
        else if (cur-1 >= 0 && q[cur-1] == c) cur--;
        else if (cur+1 < q.size() && q[cur+1] == c) cur++;
        else if (used[c]) {
            cout << "NO\n";
            return;
        }
        else if (cur == 0) q.push_front(c), used[c] = 1;
        else if (cur+1 == q.size()) q.push_back(c), cur++, used[c] = 1;
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 'a'; i <= 'z'; i++) {
        if (not used[i]) q.push_back(i);
    }

    for (char c : q) cout << c;
    cout << '\n';
}

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif

    int t; cin >> t;
    while (t--)
        solve();

}
