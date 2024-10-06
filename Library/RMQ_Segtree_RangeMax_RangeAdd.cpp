/*
 * 0-based Range-max Range-add segtree
 * Open intervals
 *
 * Build: O(n)
 * Update: O(logn)
 * Query: O(logn)
 *
 * For min, change the lines marked with ###
 *
 */

#define MAXN 1000006

int n;
long long T[MAXN << 2], D[MAXN << 2];
long long a[MAXN];

void maintain(int id) { // maintain node query value from l and r child
    T[id] = max(T[id << 1], T[id << 1 | 1]); // ###
}

void apply(int id, long long val) {
    T[id] += val; // actual query results
    D[id] += val; // passing on upd to children
}

void push(int id) { // apply 'below' upd range, pass upd to children
    apply(id << 1, D[id]);
    apply(id << 1 | 1, D[id]);
    D[id] = 0; // NO_MARK = 0x3fffffff; (maybe use push_need/push_val ?)
}

void build(int id = 1, int l = 0, int r = n) {
    D[id] = 0;
    if (l+1 == r) { // at leaf (unit-length)
        T[id] = a[l]; // query value for single array value
        return;
    }
    build(id << 1, l, l + r >> 1);
    build(id << 1 | 1, l+r >> 1, r);

    maintain(id); // maintain cur node after child change
}

void upd(int x, int y, long long v, int id = 1, int l = 0, int r = n) {
    if (y <= l || r <= x) return;
    if (x <= l && r <= y) { // cur node completely within update range, apply
        apply(id, v);
        return;
    }
    push(id); // upd covers cur node partially, so push

    upd(x, y, v, id << 1, l, l + r >> 1);
    upd(x, y, v, id << 1 | 1, l + r >> 1, r);

    maintain(id); // maintain cur node after child change
}

int ask(int x, int y, int id = 1, int l = 0, int r = n) {
    if (y <= l || r <= x)
        return 0; // sentiel value not affecting output  // ###
    if (x <= l && r <= y)
        return T[id];

    push(id); // children not yet updated, push

    return max(ask(x, y, id << 1, l, l + r >> 1),
               ask(x, y, id << 1 | 1, l + r >> 1, r)); // ###
}

/*
 * Usage:
 *
 * 0-based
 *
 * 0. Init a[]
 * 1. build();
 * 2. upd(l, r, add_val) (open interval, 0-based)
 *
 */