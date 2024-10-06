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

#define DEBUG 0
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 3000006
//#define MOD 998244353LL
#define MOD 1000000007LL

int n;
long long l[MAXN], h[MAXN], w[MAXN];
long long p[MAXN];
vector<int> vals;

void get_input() {
    int k;
    long long a, b, c, d;
    cin >> n >> k;

    for (int i = 1; i <= k; i++)
        cin >> l[i];
    cin >> a >> b >> c >> d;
    for (int i = k+1; i <= n; i++)
        l[i] = (a*l[i-2]+b*l[i-1]+c) % d + 1;

    for (int i = 1; i <= k; i++)
        cin >> w[i];
    cin >> a >> b >> c >> d;
    for (int i = k+1; i <= n; i++)
        w[i] = (a*w[i-2]+b*w[i-1]+c) % d + 1;

    for (int i = 1; i <= k; i++)
        cin >> h[i];
    cin >> a >> b >> c >> d;
    for (int i = k+1; i <= n; i++)
        h[i] = (a*h[i-2]+b*h[i-1]+c) % d + 1;
}

struct node{
    long long l, r, h, p;
};

node T[MAXN << 2];
long long D[MAXN << 2];

void apply(int id, int v, int l, int r) {
    if (T[id].h >= v) return;
    cerr << "apply " << id << ' ' << v << '\n';
    T[id].l = T[id].r = T[id].h = v;
    T[id].p = (vals[r]-vals[l])*2+T[id].l+T[id].r;
    T[id].p %= MOD;
//    T[id].p = (r-l)*2+T[id].l+T[id].r;
    D[id] = v; // passing on upd to children
}

void push(int id, int l, int r) {
    cerr << "push " << id << '\n';
    apply(id<<1, D[id], l,l+r>>1);
    apply(id<<1|1, D[id], l+r>>1,r);
    D[id] = 0;
}

void maintain(int id) {
    cerr << "maintain " << id << '\n';
    T[id].l = T[id<<1].l;
    T[id].r = T[id<<1|1].r;
    T[id].p = T[id<<1].p + T[id<<1|1].p - min(T[id<<1].r, T[id<<1|1].l)*2;
    T[id].p %= MOD;
}

void upd(int x, int y, int v, int id=1, int l=0, int r=2*n+5){
    cerr << id << ' ' << l << ' ' << r << '\n';
    if (y<=l || r<=x) return;
    if (x<=l && r<=y){ // cur node completely within upd range, so apply
        apply(id, v, l, r);
        return;
    }
    push(id, l, r); // upd only covers cur node partially, so push
    upd(x,y,v,id<<1,l,l+r>>1);
    upd(x,y,v,id<<1|1,l+r>>1,r);
    maintain(id); // maintain cur node after child change
}

void solve() {
    get_input();
//    for (int i = 1; i <= n; i++) cout << l[i] << ' '; cout << '\n';
//    for (int i = 1; i <= n; i++) cout << h[i] << ' '; cout << '\n';
//    for (int i = 1; i <= n; i++) cout << w[i] << ' '; cout << '\n';
    vals.clear();
    for (int i = 1; i <= n; i++) {
        vals.pb(l[i]);
        vals.pb(l[i]+w[i]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (long long i = 1; i <= n; i++) {
        int lx = lower_bound(vals.begin(), vals.end(), l[i])-vals.begin();
        int rx = lower_bound(vals.begin(), vals.end(), l[i]+w[i])-vals.begin();
        upd(lx, rx, h[i]);
        p[i] = T[1].p;
    }

//    for (int i = 1; i <= n; i++) {
//        upd(l[i], l[i]+w[i], h[i]);
//        cout << "perimeter " << T[1].p << '\n';
//    }

    for (int i = 1; i < ((2*n+5) << 2); i++) {
        D[i] = 0;
        T[i].h = T[i].l = T[i].r = T[i].p = 0;
    }

//    for (int i = 1; i <= n; i++) cout << p[i] << ' '; cout << '\n';

    long long ans = 1;
    for (int i = 1; i <= n; i++)
        (ans *= p[i] % MOD) %= MOD;
    cout << ans << '\n';
}

int main() {
#ifdef LOCAL
//    freopen("perimetric_chapter_3_validation_input.txt", "r", stdin);
    freopen("perimetric_chapter_3_input.txt", "r", stdin);
//    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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