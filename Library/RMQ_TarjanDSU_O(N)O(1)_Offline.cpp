vector<int> TarjanRMQ(vector<int> a, vector<pii> queries) { // 0-based, closed interval, offline query
	int n = a.size();
	vector<int> qu[n+5];
	DSU dsu(n);

	vector<int> ans(queries.size());
	stack<int> st;

	for (int i = 0; i < queries.size(); i++)
		qu[queries[i].se].push_back(i);

	for(int i = 0; i < n; i++){
		while(st.size() && a[st.top()] <= a[i]) // ### >= for min, <= for max
			dsu.par[st.top()] = i, st.pop();
		st.push(i);
		for(auto qi : qu[i])
			ans[qi] = a[dsu.get(queries[qi].fi)];
	}
	return ans;
};

// Reference: https://codeforces.com/blog/entry/48994

// RMQ Tester: https://judge.hkoi.org/task/M0921

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<pii> qs;
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r;
		l--; r--;
		qs.pb(mp(l, r));
	}
	auto ans = TarjanRMQ(a, qs);
	for (int x : ans) cout << x << '\n';
}
