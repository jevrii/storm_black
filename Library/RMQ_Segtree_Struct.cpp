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

template <class Type>
struct SegmentTree {
	vector<Type> T, D, a;
	int n;

	SegmentTree(int _n, Type _default_value = 0) {
		n = _n;
		T.resize((n+5) * 4);
		fill(T.begin(), T.end(), _default_value);

		D.resize((n+5) * 4);
		fill(D.begin(), D.end(), 0);

		a.resize((n+5));
	}

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

	void build(int id = 1, int l = 0, int r = -1) {
		if (r == -1) r = n;
		if (l+1 == r) { // at leaf (unit-length)
			T[id] = a[l]; // query value for single array value
			return;
		}
		build(id << 1, l, l + r >> 1);
		build(id << 1 | 1, l+r >> 1, r);

		maintain(id); // maintain cur node after child change
	}

	void upd(int x, int y, long long v, int id = 1, int l = 0, int r = -1) {
		if (r == -1) r = n;
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

	int ask(int x, int y, int id = 1, int l = 0, int r = -1) {
		if (r == -1) r = n;
		if (y <= l || r <= x)
			return 0; // sentiel value not affecting output  // ###
		if (x <= l && r <= y)
			return T[id];

		push(id); // children not yet updated, push

		return max(ask(x, y, id << 1, l, l + r >> 1),
				   ask(x, y, id << 1 | 1, l + r >> 1, r)); // ###
	}
};


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

void solve() {
	int n, q;
	cin >> n >> q;
	SegmentTree<int> T(n);
	for (int i = 0; i < n; i++)
		cin >> T.a[i];
	T.build();

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << T.ask(l-1, r) << '\n';
	}
}