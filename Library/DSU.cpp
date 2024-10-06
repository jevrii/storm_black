struct DSU {
	int n;
	vector<int> par, sz;

	void init(int _n) {
		n = _n;
		par.resize(n+5); iota(par.begin(), par.end(), 0);
		sz.resize(n+5); fill(sz.begin(), sz.end(), 1);
	}

	DSU(int _n) {
		init(_n);
	}

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
};
