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
#define INF 0x3f3f3f3f3f3f3f3f
//#define MOD 998244353LL
#define MOD 1000000007LL

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {1,0,-1,1,-1,1,0,-1};

void solve() {
    vector<string> cur(91);
    for (int i = 0; i < 91; i++)
        cin >> cur[i];
    while (1) {
        vector<string> nxt = cur;
        for (int x = 0; x < 91; x++)
            for (int y = 0; y < 99; y++) {
                int cnt = 0;
                for (int d = 0; d < 8; d++) {
                    int nx = x+dx[d], ny = y+dy[d];
                    while (!(nx < 0 || ny < 0 || nx >= 91 || ny >= 99) && cur[nx][ny] == '.')
                        nx += dx[d], ny += dy[d];
                    if (nx < 0 || ny < 0 || nx >= 91 || ny >= 99) continue;
                    cnt += (cur[nx][ny] == '#');
                }
                if (cur[x][y] == 'L') {
                    if (cnt == 0) nxt[x][y] = '#';
                }

                if (cur[x][y] == '#') {
                    if (cnt >= 5) nxt[x][y] = 'L';
                }
            }
        if (cur == nxt)
            break;
        cur = nxt;
    }

    int ans = 0;
    for (string s : cur)
        ans += count(s.begin(), s.end(), '#');
    cout << ans << '\n';
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