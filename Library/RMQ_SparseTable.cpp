// Sparse RMQ: https://codeforces.com/blog/entry/75611

#define LOGN 22

int mn[LOGN][MAXN];

int rmq(int l, int r) { // [l; r)
	int t = __lg(r - l);
	return max(mn[t][l], mn[t][r - (1 << t)]); // ###
}

void sparse_init(int dat[], int n) {
	memcpy(mn[0], dat, sizeof(int) * n);
	for (int l = 0; l < LOGN - 1; l++)
		for (int i = 0; i + (2 << l) <= n; i++)
			mn[l+1][i] = max(mn[l][i], mn[l][i + (1 << l)]); // ###
}

// Tester

void solve() {
	int n, q; cin >> n >> q;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	sparse_init(a, n);

	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r;
		cout << rmq(l-1, r) << '\n';
	}
}
