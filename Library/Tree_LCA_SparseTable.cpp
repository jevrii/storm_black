#define MAXN 100005
#define LGN 20
int n;

int tab[LGN][MAXN<<1];
vector<int> e[MAXN], euler;
int en[MAXN], ed[MAXN], d[MAXN];

void dfs(int now, int dep = 0, int prv = -1){
    en[now] = euler.size();
    d[now] = dep + 1;
    euler.push_back(now);
    for(auto x: e[now]){
        if(x != prv){
            dfs(x, dep+1, now);
            euler.push_back(now);
        }
    }
    ed[now] = euler.size();

    return;
}

void build(){
    int n = euler.size(); // n = 2*n-1
    for(int i = 0; i < n; i++){
        tab[0][i] = euler[i];
    }

    for(int i = 1; i < LGN; i++){
        for(int j = 0; j+(1<<i) <= n; j++){
            int x = tab[i-1][j];
            int y = tab[i-1][j+(1<<(i-1))];
            if(d[x] < d[y]) tab[i][j] = x;
            else tab[i][j] = y;
        } }

    return;
}

int ask(int x, int y){
    if (en[x] > en[y]) swap(x, y);
    x = en[x]; y = ed[y];
    int h = __lg(y-x); // lg2(y - x)
    int u = tab[h][x];
    int v = tab[h][y - (1<<h)];

    if(d[u] < d[v]) return u;
    else return v;
}

int dis(int x, int y) {
    int lca = ask(x, y);
    return d[x] + d[y] - 2*d[lca];
}

/*
 * Usage:
 * 1. dfs(root);
 * 2. build();
 * 3. lca = ask(u, v)
 *
 * Test task: https://codeforces.com/problemset/problem/1304/E
 *
 */