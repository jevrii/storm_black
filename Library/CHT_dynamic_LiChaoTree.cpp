template<typename T, T minX, T maxX, T defVal>
struct DynamicLiChaoTree { // maximum values
private:
    struct Line {
        T a, b;
        inline T calc(T x) const { return a * x + b; }
    };
    struct Node {
        Line val = {0, defVal};
        Node *lt = nullptr, *rt = nullptr;
    };
    Node* root;
    vector<Node*> listNode;
    void update(Node* cur, T l, T r, T u, T v, Line nw) {
        if (v < l || r < u) return;
        T mid = (l + r) >> 1;
        if (u <= l && r <= v) {
            if (cur->val.calc(l) >= nw.calc(l)) swap(cur->val, nw);
            if (cur->val.calc(r) <= nw.calc(r)) {
                cur->val = nw;
                return;
            }
            if (nw.calc(mid) >= cur->val.calc(mid)) {
                if (!cur->rt) cur->rt = new Node(), listNode.push_back(cur->rt);
                update(cur->rt, mid + 1, r, u, v, cur->val);
                cur->val = nw;
            } else {
                if (!cur->lt) cur->lt = new Node(), listNode.push_back(cur->lt);
                update(cur->lt, l, mid, u, v, nw);
            }
        } else {
            if (!cur->rt) cur->rt = new Node(), listNode.push_back(cur->lt);
            if (!cur->lt) cur->lt = new Node(), listNode.push_back(cur->rt);
            update(cur->lt, l, mid, u, v, nw);
            update(cur->rt, mid + 1, r, u, v, nw);
        }
    }
    T query(Node* cur, T l, T r, T x) {
        T res = cur->val.calc(x);
        T mid = (l + r) >> 1;
        if (x <= mid && cur->lt)
            res = max(res, query(cur->lt, l, mid, x));
        else if (x > mid && cur-> rt)
            res = max(res, query(cur->rt, mid + 1, r, x));
        return res;
    }
public:
    void addLine(Line line, T l = minX, T r = maxX) {
        update(root, minX, maxX, l, r, line);
    }
    T query(T x) {
        return query(root, minX, maxX, x);
    }
    void init() {
        for (auto ptr: listNode) delete(ptr);
        root = new Node;
        listNode.clear();
        listNode.push_back(root);
    }
};

/*
 * Usage:
 * Query maximum. Negate m,c,query result for minimum.
 *
 * 1. DynamicLiChaoTree<long long, 1, (ll)1e9+10, -ll(1e18)> s; // type, minX, maxX, default value
 * 2. s.init();
 * 3. s.addLine({m, c});
 * 4. s.query(x);
 *
 */