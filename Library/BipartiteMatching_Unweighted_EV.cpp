int match[MAXN], vis[MAXN]; // match[]: the partner of that node
vector<int> e[MAXN];

bool dfs(int v){
    if (vis[v]) return 0; vis[v]=1;
    for (int u : e[v]){
        if (match[u] == -1 || dfs(match[u])){
            match[v] = u, match[u] = v;
            return 1;
        }
    }
    return 0;
}

int MCBM(int N){ // vertices should be numbered from 0 to N-1, undirected edges
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < N; i++)
        if (match[i] == -1) {
            fill(vis, vis+N, 0);
            ans += dfs(i);
        }
    return ans;
}