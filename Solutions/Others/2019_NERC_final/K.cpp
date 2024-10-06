#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

int pas[25][25];
int cnt[25];

void solve() {
    memset(cnt, 0, sizeof(cnt));
    long long x; cin >> x;
    int k = 0;
    for (int d = 2; x > 0 && d <= 100; x/=d, d++) {
        cnt[x%d]++;
        k++;
    }
    int fi = -1;
    for (int d = 0; d < k; d++) {
        if (cnt[d]) {
            fi = d;
            break;
        }
    }
    long long a1 = 1, a2 = not fi;
    for (int acc = 0, dig = 20; dig > fi; acc += cnt[dig], dig--) {
        if (not cnt[dig]) continue;
        a1 *= pas[k-dig+1-acc][cnt[dig]];
    }
    for (int acc = 0, dig = 20; dig > fi; acc += cnt[dig], dig--) {
        if (not cnt[dig]) continue;
        a2 *= pas[k-dig+1-acc -1][cnt[dig]];
    }
    cout << a1 - a2 - 1 << '\n';
}

int main() {
//    ios_base::sync_with_stdio(0); cin.tie(0);

    for (int i = 0; i <= 20; i++) pas[i][i] = pas[i][0] = 1;
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j<= 20; j++) pas[i][j] = pas[i-1][j] + pas[i-1][j-1];

    int t; cin >> t;
    while (t--) solve();

}
/*
 * 1 2 3 4 5 6 7 8
 *
 * 0 0 0 0 2 3 3 4
 */