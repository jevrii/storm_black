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
#define MAXN 200005
#define MOD 998244353LL

long long x[105], y[105];
int n;
int ans = 0;

pii frac(pii x){
    if (x.se==0) return {1,0};
    if (x.fi==0) return {0,1};
    int g = __gcd(abs(x.fi),abs(x.se));
    if (x.se<0) g*=-1;
    return {x.fi/g, x.se/g};
}

int par[105], sz[105], done[105];

int get(int x) {
    return par[x] == x ? x : par[x] = get(par[x]);
}

bool join(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return 0;
    par[x] = y;
    sz[y] += sz[x];
    return 1;
}

int size(int x) {
    return sz[get(x)];
}

void work(pii slope) {
    for (int i = 0; i < n; i++)
        par[i] = i, sz[i] = 1, done[i] = 0;

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            if (frac({y[i]-y[j], x[i]-x[j]}) == slope) {
                join(i, j);
            }
        }

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int id = get(i);
        if (not done[id]) {
            done[id] = 1;
            v.pb(sz[id]);
        }
    }

    int c1 = 0;
    int odd = 0;
    int cur = 0;
    for (int x : v) {
        if (x >= 2) {
            cur += x - x%2; // odd is bad, need skip hole
            if (x%2) odd++;
        }
        if (x == 1) c1++;
    }
    if (odd == 2 and c1 == 1) {
        ans = max(ans, 7);
        return;
    }
    cur += min(c1 + odd, 2);
    ans = max(ans, cur);
}

void solve() {
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            work(frac({y[i]-y[j], x[i]-x[j]}));
        }

    cout << ans << '\n';

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