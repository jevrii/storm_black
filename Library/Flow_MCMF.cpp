typedef int flow_t, cost_t;
const int MAXN = 405, MAXM = 1505, DIRECTED = 0, UNDIRECTED = 1;
const flow_t FLOW_INFTY = 0x3fffffff;
const cost_t COST_INFTY = 0x3fffffff;
int N, S, T, now, K;
bool inQ[MAXN];

struct edge {
    flow_t remain;
    cost_t cost;
    int endVertexId, nextEdgeId;
}e[MAXM << 1];

struct vertex {
    int firstEdgeId, firstUnsaturEdgeId;
    cost_t level;
}v[MAXN];

void _addEdge(int begin, int end, flow_t c, cost_t w) {
    e[now].remain = c;
    e[now].cost = w;
    e[now].endVertexId = end;
    e[now].nextEdgeId = v[begin].firstEdgeId;
    v[begin].firstEdgeId = now++;
}

void addEdge(int begin, int end, flow_t c, int edgeType, cost_t w = 1) {
    _addEdge(begin, end, c, w);
    _addEdge(end, begin, edgeType * c, -w);
}

void init() {
    now = 0;
    for (int i = 0; i < N; ++i) v[i].firstEdgeId = -1, inQ[i] = false;
}

bool markLevel(){ // SPFA
    for (int i = 0; i < N; ++i)
        v[i].level = COST_INFTY, v[i].firstUnsaturEdgeId =
                v[i].firstEdgeId, inQ[i] = false;
    v[S].level = 0;
    queue<int> Q;
    Q.push(S);
    inQ[S] = true;
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        inQ[x] = false;
        for (int i = v[x].firstEdgeId; i >= 0; i = e[i].nextEdgeId) {
            if (e[i].remain && v[e[i].endVertexId].level > v[x].level + e[i].cost)
            {
                v[e[i].endVertexId].level = v[x].level + e[i].cost;
                if (!inQ[e[i].endVertexId])
                    Q.push(e[i].endVertexId), inQ[e[i].endVertexId] = true;
            } } }
    return v[T].level < COST_INFTY;
}

flow_t extendFlow(int x, flow_t flow) {
    if (x == T) return flow;
    inQ[x] = true;
    flow_t t, total = 0;
    for (int &i = v[x].firstUnsaturEdgeId; i >= 0; i = e[i].nextEdgeId) {
        if (v[e[i].endVertexId].level == v[x].level + e[i].cost && e[i].remain
            && !inQ[e[i].endVertexId]) {
            if (t = extendFlow(e[i].endVertexId, min(flow, e[i].remain)))
                e[i].remain -= t, e[i ^ 1].remain += t, flow -= t, total += t;
            if (0 == flow) break;
        } }
    inQ[x] = false;
    return total;
}

flow_t Dinic() {
    flow_t flow, total = 0;
    cost_t cost = 0;
    while (markLevel())
        while (flow = extendFlow(S, FLOW_INFTY)) // min-cost flow: && cost <= 0
            total += flow, cost += flow * v[T].level;
    return cost; // Return total in maxFlow; return cost in minCostMaxFlow
}

void buildGraph() {
// Assign N (number of vertices), S (source) and T (sink) here.
// Vertices numbered from 0 to N - 1. So S and T should be in [0, N).
    init();
// Add edges here
}