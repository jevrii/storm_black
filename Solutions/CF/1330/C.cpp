#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";
#define INF 0x3f3f3f3f3f3f3f3f

#define MAXN 100005
#define MOD 998244353LL

int len[MAXN], n, m, ans[MAXN];

long long T[MAXN << 2], D[MAXN << 2];
long long a[MAXN];

void maintain(int id) { // maintain node query value from l and r child
	T[id] = max(T[id << 1], T[id << 1 | 1]);
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

void build(int id = 1, int l = 0, int r = m) {
	D[id] = 0;
	if (l+1 == r) { // at leaf (unit-length)
		T[id] = a[l]; // query value for single array value
		return;
	}
	build(id << 1, l, l + r >> 1);
	build(id << 1 | 1, l+r >> 1, r);

	maintain(id); // maintain cur node after child change
}

void upd(int x, int y, long long v, int id = 1, int l = 0, int r = m) {
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

int ask(int x, int y, int id = 1, int l = 0, int r = m) {
	if (y <= l || r <= x)
		return 0; // sentiel value not affecting output
	if (x <= l && r <= y)
		return T[id];

	push(id); // children not yet updated, push

	return max(ask(x, y, id << 1, l, l + r >> 1),
			   ask(x, y, id << 1 | 1, l + r >> 1, r));
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> len[i];
	}

	for (int i = 0; i < m; i++) {
		a[i] = i+len[i];
	}
	build();

	for (int i = 1; i < m; i++) {
		while (ask(i, m) < n && ask(i,i+1)-len[i] < ask(i-1, i)) {
			upd(i, m, 1);
		}
	}

	for (int i = 0; i < m; i++) {
		ans[i] = ask(i, i+1) + 1 - len[i];
	}

	if (ask(0, m) < n || ask(0, m) > n) {
		cout << -1 << '\n';
		return;
	}

	for (int i = 0; i < m; i++) {
		cout << ans[i] << " \n"[i+1==m];
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}