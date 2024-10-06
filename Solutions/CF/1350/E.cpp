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

char a[1005][1005];
long long dis[1005][1005];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

void solve() {
    int n, m, nq;
    cin >> n >> m >> nq;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    memset(dis, INF, sizeof(dis));
    queue<pii> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            bool have_same = 0;
            for (int d = 0; d < 4; d++) {
                have_same |= (a[i+dx[d]][j+dy[d]] == a[i][j]);
            }
            if (have_same) {
                q.push(mp(i, j));
                dis[i][j] = 0;
            }
        }
    }

    while (q.size()) {
        int x, y; tie(x, y) = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x+dx[d], ny = y+dy[d];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
                if (dis[nx][ny] == INF) {
                    q.push(mp(nx, ny));
                    dis[nx][ny] = dis[x][y]+1;
                }
            }
        }
    }

    while (nq--) {
        long long x, y, iter;
        cin >> x >> y >> iter;
        if (iter < dis[x][y]) cout << a[x][y] << '\n';
        else cout << (char)(a[x][y]^((iter-dis[x][y])%2)) << '\n';
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