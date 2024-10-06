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

int vis[505][505][505], dis[505][505][505];
int n, target;

struct station {
    int cost;
    int dx;
    int dy;
};

struct state {
    int cur;
    int x;
    int y;
};

station a[25];

void solve() {
    cin >> n >> target;
    for (int i = 0; i < n; i++) {
        cin >> a[i].cost >> a[i].dx >> a[i].dy;
    }
    queue<state> q;
    q.push({0, 1, 0});
    vis[0][1][0] = 1;

    while (q.size()) {
        state t = q.front(); q.pop();
        if (t.cur >= target) {
            cout << dis[t.cur][t.x][t.y] << '\n';
            return;
        }
        for (int i = 0; i < n; i++) {
            if (a[i].cost <= t.cur) {
                int nc = min(500, t.cur - a[i].cost + t.y);
                int nx = min(500, t.x + a[i].dx);
                int ny = min(500, t.y + a[i].dy);

                if (not vis[nc][nx][ny]) {
                    q.push({nc, nx, ny});
                    vis[nc][nx][ny] = 1;
                    dis[nc][nx][ny] = dis[t.cur][t.x][t.y] + 1;
                }
            }
        }
        int nc = min(500, t.cur + t.x + t.y);
        int nx = t.x;
        int ny = t.y;

        if (not vis[nc][nx][ny]) {
            q.push({nc, nx, ny});
            vis[nc][nx][ny] = 1;
            dis[nc][nx][ny] = dis[t.cur][t.x][t.y] + 1;
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
//    cin >> t;
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}