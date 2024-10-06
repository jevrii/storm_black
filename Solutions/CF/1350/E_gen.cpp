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
#define MAXN 2000006
#define MOD 998244353LL

char a[1005][1005], nxt[1005][1005], orig[1005][1005];
int dis[1005][1005];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            orig[i][j] = a[i][j];
        }
    memset(dis, -1, sizeof(dis));

    for (int iter = 0; iter < 50; iter++) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                bool have_same = 0;
                for (int d = 0; d < 4; d++) {
                    have_same |= (a[i+dx[d]][j+dy[d]] == a[i][j]);
                }
                if (have_same) nxt[i][j] = a[i][j] ^ 1;
                else nxt[i][j] = a[i][j];
            }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                bool have_same = 0;
                for (int d = 0; d < 4; d++) {
                    have_same |= (a[i+dx[d]][j+dy[d]] == a[i][j]);
                }
                if (have_same) {
                    if (dis[i][j] == -1) dis[i][j] = iter;
//                    cout << dis[i][j];
                    cout << (char)(orig[i][j]^((iter-dis[i][j])%2));
                }
                else cout << ' ';
//                cout << a[i][j];
            }
            cout << '\n';
        }

        cout << "        \n";

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << a[i][j];
//                else cout << ' ';
            }
            cout << '\n';
        }

        cout << "-------\n";
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                a[i][j] = nxt[i][j];
            }
    }



}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    auto start_time = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}