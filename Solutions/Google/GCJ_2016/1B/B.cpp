#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 500005
#define MOD 998244353LL

long long val(pair<string, string> p) {
    return abs(stoll(p.fi) - stoll(p.se));
}

pair<string, string> solve(string a, string b) {
    int n = a.size();
    int sgn = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == '?' && b[i] == '?') {
            if (sgn == 0) {
                long long best = val(solve(string(1, '0') + a.substr( i+1), string(1, '0') + b.substr(i+1)));
                a[i] = b[i] = '0';
                for (char c1 = '0'; c1 <= '1'; c1++) {
                    for (char c2 = '0'; c2 <= '1'; c2++) {
                        if (c1 == c2) continue;
                        long long d = val(solve(string(1, c1) + a.substr( i+1), string(1, c2) + b.substr(i+1)));
                        if (d < best) {
                            best = d;
                            a[i] = c1;
                            b[i] = c2;
                            sgn = c1-c2;
                        }
                    }
                }
            }
            else if (sgn > 0) a[i] = '0', b[i] = '9';
            else if (sgn < 0) a[i] = '9', b[i] = '0';
        }
        else if (a[i] == '?' && b[i] != '?') {
            if (sgn == 0) {
                long long best = LLONG_MAX;
                for (char c = max((int)'0', b[i]-1); c <= min((int)'9', b[i]+1); c++) {
                    long long d = val(solve(string(1, c) + a.substr(i+1), b.substr(i)));
                    if (d < best) {
                        best = d;
                        a[i] = c;
                        sgn = c-b[i];
                    }
                }
            }
            else if (sgn > 0) a[i] = '0';
            else if (sgn < 0) a[i] = '9';
        }
        else if (a[i] != '?' && b[i] == '?') {
            if (sgn == 0) {
                long long best = LLONG_MAX;
                for (char c = max((int)'0', a[i]-1); c <= min((int)'9', a[i]+1); c++) {
                    long long d = val(solve(a.substr(i), string(1, c) + b.substr(i+1)));
                    if (d < best) {
                        best = d;
                        b[i] = c;
                        sgn = a[i]-c;
                    }
                }
            }
            else if (sgn > 0) b[i] = '9';
            else if (sgn < 0) b[i] = '0';
        }
        else {
            if (a[i] > b[i]) {
                if (sgn == 0) sgn = 1;
            }
            else if (a[i] < b[i]) {
                if (sgn == 0) sgn = -1;
            }
        }
    }

    return mp(a, b);
}

void solve() {
    string a, b;
    cin >> a >> b;

    auto ans = solve(a, b);
    cout << ans.fi << ' ' << ans.se << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    auto start_time = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for (int no = 1; no <= t; no++) {
        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}