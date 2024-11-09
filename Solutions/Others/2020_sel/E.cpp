#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize ("trapv")
using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;

#define MAXN 1000006
#define INF 0x3f3f3f3f
//#define MOD 998244353LL
#define MOD 1000000007LL

char a[55][55];
int ans[55][55];
int d[55][55], ddq[55][55], d2[55][55];
int vis[55][55];
int n, m, nq;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void work(int sx, int sy) {
    memset(d2, 0, sizeof(d2));
    memset(vis, 0, sizeof(vis));
    queue<pii> q;
    q.push(mp(sx, sy));
    vis[sx][sy] = 1;
    while (q.size()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (!(1 <= nx && nx <= n)) continue;
            if (!(1 <= ny && ny <= m)) continue;
            if (vis[nx][ny]) continue;
            if (a[nx][ny] != '.' && a[nx][ny] != 'E') continue; // blocked

            d2[nx][ny] = d2[x][y] + 1;
            q.push(mp(nx, ny));
            vis[nx][ny] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'E') {
                ddq[sx][sy] = d2[i][j];
            }
        }
}

void solve() {
    cout << '\n';
    cin >> n >> m >> nq;
    memset(a, 0, sizeof(a));

    queue<pii> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'E') {
                q.push(mp(i, j));
                vis[i][j] = 1;
            }
        }
    }

    memset(vis, 0, sizeof(vis));
    memset(d, -1, sizeof(d));
    d[q.front().fi][q.front().se] = 0;

    while (q.size()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        cerr << x << ' ' << y << ' ' << d[x][y] << '\n';
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (!(1 <= nx && nx <= n)) continue;
            if (!(1 <= ny && ny <= m)) continue;
            if (vis[nx][ny]) continue;
            if (a[nx][ny] != '.') continue; // blocked

            d[nx][ny] = d[x][y] + 1;
            q.push(mp(nx, ny));
            cerr << "push " << nx << ' ' << ny << '\n';
            vis[nx][ny] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '?') {
                work(i, j);
            }
        }

    while (nq--) {
        int x, y;
        cin >> x >> y;
        if (a[x][y] != '?') {
            cout << d[x][y] << '\n';
        }
        else {
            cout << ddq[x][y] << '\n';
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    auto start_time = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for (int no = 1; no <= t; no++) {
        cout << "Case " << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}