// 1327F

#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define MAXN 500005
#define INF 0x3f3f3f3f3f3f3f3f
#define MOD 998244353LL
#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

int len, k, m;
vector<pair<pii, int> > seg;
int set_bit[MAXN], dpps[MAXN], fin[MAXN];

long long work(int bit) {
	memset(set_bit, 0, sizeof(set_bit));
	memset(dpps, 0, sizeof(dpps));
	memset(fin, 0, sizeof(fin));

	for (auto op : seg) {
		if (op.se == 0) continue;
		int l, r; tie(l, r) = op.fi;
		set_bit[l]++;
		set_bit[r+1]--;
	}

	partial_sum(set_bit, set_bit+MAXN, set_bit);
	for (int i = 0; i < MAXN; i++)
		set_bit[i] = !!set_bit[i];
	partial_sum(set_bit, set_bit+MAXN, set_bit);

	for (auto op : seg) {
		if (op.se == 1) continue;
		int l, r; tie(l, r) = op.fi;
		if (set_bit[r]-set_bit[l-1] == r-l+1) { // all 1 in this 0seg
			return 0;
		}
		fin[r] = max(fin[r], l);
	}

	int cur;
	dpps[0] = 1;
	for (int pos = 1, lx = 0; pos <= len + 1; pos++) {
		cur = 0;
		if (set_bit[pos] == set_bit[pos-1])
			cur = (dpps[pos-1] - (lx ? dpps[lx-1] : 0) + MOD) % MOD;
		dpps[pos] = (dpps[pos-1] + cur) % MOD;
		lx = max(lx, fin[pos]);
	}

	return cur;
}

pair<pii, int> req[MAXN];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> len >> k >> m;
	for (int i = 0, l, r, x; i < m; i++) {
		cin >> l >> r >> x;
		req[i] = mp(mp(l, r), x);
		seg.pb(mp(req[i].fi, -1));
	}

	long long ans = 1;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < m; j++) {
			seg[j].se = !!(req[j].se & (1 << i));
		}
		long long val = work(i);
		(ans *= val) %= MOD;
	}

	cout << ans << '\n';
}