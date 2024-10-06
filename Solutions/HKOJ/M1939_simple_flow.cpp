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
//#define MAXN 200005
#define MOD 998244353LL

#define SHIFT 20000020

#define MAXN 505
int cap[MAXN][MAXN],N,S,T,lay[MAXN],f,flow,vis[MAXN];
queue<int> q;
int bfs() {
    memset(lay,0,sizeof(lay));
    while (!q.empty()) q.pop();
    q.push(S);
    lay[S]=1;
    while (!q.empty()) {
        int cur=q.front(); q.pop();
        for (int v=0;v<N;v++) {
            if (cap[cur][v]>0 && lay[v]==0) {
                lay[v]=lay[cur]+1;
                q.push(v);
                if (v==T) return lay[T];
            } } }
    return 0;
}
int dfs(int cur,int lc) {
    if (cur==T) return lc;
    vis[cur]=1;
    for (int v=0;v<N;v++) {
        if (cap[cur][v]>0 && lay[v]==lay[cur]+1 && !vis[v]) {
            int tmp=dfs(v,min(lc,cap[cur][v]));
            if (tmp>0) {
                cap[cur][v]-=tmp;
                cap[v][cur]+=tmp;
                return tmp;
            } } }
    return 0;
}
void addEdge(int u, int v, int val, int type){
    cap[u][v]=val;
    cap[v][u]=val*type;
}

int Dinic() {
    while (bfs()) {
        while (1) {
            memset(vis,0,sizeof(vis));
            f=dfs(S,1e9);
            if (f==0) break;
            flow+=f;
        } }
    return flow;
}

void solve() {
    int n;
    cin >> n;
    vector<int> m(n+1), d(n+1), l(n+1);
    for (int i = 1; i <= n; i++)
        cin >> m[i] >> d[i] >> l[i];

    S = 0;
    N = 1+n+2+1;
    int d1 = n+1;
    int d2 = n+2;
    T = N-1;

    for (int i = 1; i <= n; i++) {
        addEdge(0, i, m[i], 0);
        addEdge(i, d1, l[i], 0);
        if (d[i] == 2)
            addEdge(i, d2, l[i], 0);
    }
    addEdge(d1, T, 1440, 0);
    addEdge(d2, T, 1440, 0);

    int ans = Dinic();
    if (ans != accumulate(m.begin(), m.end(), 0)) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            cout << l[i]-cap[i][d1] << ' ' << (d[i]==1?0:l[i]-cap[i][d2]) << '\n';
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