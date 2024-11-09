#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

int n, l, k;
string s;
char ans[1005][1005];
queue<char> q;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> l >> k;
    cin >> s;
    sort(s.begin(), s.end());
    for (char c : s) q.push(c);

    for (int i = 1; i <= k; i++) {
        ans[i][0] = q.front(); q.pop();
    }

    for (int i = 1; i < l; i++) {
        int r = 0;
        for (int j = k; j >= 0; j--) {
            if (ans[j][i-1] == ans[k][i-1]) r++;
            else break;
        }

        for (int j = k - r + 1; j <= k; j++) {
            ans[j][i] = q.front(); q.pop();
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < l; j++) {
            if (not ans[i][j])
                ans[i][j] = q.front(), q.pop();
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < l; j++) cout << ans[i][j];
        cout << '\n';
    }

}
