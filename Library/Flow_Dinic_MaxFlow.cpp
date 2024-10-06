#include <cstdio>
#include <queue>
using namespace std;
typedef int flow_t;
const int MAXN = 505, MAXM = 100005, DIRECTED = 0, UNDIRECTED = 1;
const flow_t INFTY = 0x3fffffff;
int N, S, T, now;

struct edge {
    flow_t remain;
    int endVertexId, nextEdgeId;
}e[MAXM << 1];

struct vertex {
    int firstEdgeId, level, firstUnsaturEdgeId;
}v[MAXN];

void _addEdge(int begin, int end, flow_t c) {
    e[now].remain = c;
    e[now].endVertexId = end;
    e[now].nextEdgeId = v[begin].firstEdgeId;
    v[begin].firstEdgeId = now++;
}

void addEdge(int begin, int end, flow_t c, int edgeType) {
    _addEdge(begin, end, c);
    _addEdge(end, begin, edgeType * c);
}

void init() {
    now = 0;
    for (int i = 0; i < N; ++i) v[i].firstEdgeId = -1;
}

bool markLevel(){
    for (int i = 0; i < N; ++i)
        v[i].level = -1, v[i].firstUnsaturEdgeId = v[i].firstEdgeId;
    v[S].level = 0;
    queue<int> Q;
    Q.push(S);
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (int i = v[x].firstEdgeId; i >= 0; i = e[i].nextEdgeId)
            if (e[i].remain && v[e[i].endVertexId].level < 0)
                v[e[i].endVertexId].level = v[x].level + 1,
                        Q.push(e[i].endVertexId);
    }
    return v[T].level > 0;
}

flow_t extendFlow(int x, flow_t flow) {
    if (x == T) return flow;
    flow_t t, total = 0;
    for (int &i = v[x].firstUnsaturEdgeId; i >= 0; i = e[i].nextEdgeId) { // ref!
        if (v[e[i].endVertexId].level == v[x].level + 1 && e[i].remain) {
            if (t = extendFlow(e[i].endVertexId, min(flow, e[i].remain)))
                e[i].remain -= t, e[i ^ 1].remain += t, flow -= t, total += t;
            if (0 == flow) break; // otherwise, have flow remain after edge satur.
        } }
    return total;
}

flow_t Dinic() {
    flow_t flow, total = 0;
    while (markLevel())
        while (flow = extendFlow(S, INFTY))
            total += flow;
    return total;
}

void buildGraph() {
// Assign N (number of vertices), S (source) and T (sink) here.
// Vertices numbered from 0 to N - 1. So S and T should be in [0, N).
    init();
// Add edges here
    addEdge (u, v, capacity, [DIRECTED | UNDIRECTED]);
}

int main() {
    int nCase, n, m;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d%d", &n, &m);
        buildGraph();
        flow_t ans = Dinic();
    }
    return 0;
}