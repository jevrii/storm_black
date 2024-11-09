// 1312F

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

#define MAXN 5000006
#define MOD 998244353LL

int n, x, y, z;
int pref, loop;
int sg[2000][3];
long long a[300005];

int mex(int a, int b, int c) {
	int ret = 0;
	while (ret == a || ret == b || ret == c) ret++;
	return ret;
}

void precom() {
	bool good = 0;
	for (int st = 0; not good and st < 500; st++) {
		for (int len = 1; not good and len < 500; len++) {
			bool bad = 0;
			for (int i = st+len; i < 2000; i++) {
				for (int j = 0; j < 3; j++) {
					if (sg[(i-st)%len+st][j] != sg[i][j]) {
						bad = 1;
						break;
					}
				}
				if (bad) break;
			}
			if (not bad) {
				pref = st;
				loop = len;
				good = 1;
			}
		}
	}
}

int get_sg(long long hp, int state = 0) {
	if (hp < pref) {
		return sg[hp][state];
	}
	return sg[(hp-pref)%loop+pref][state];
}

void solve() {
	cin >> n >> x >> y >> z;
	for (int i = 1; i < 2000; i++) {
		sg[i][0] = mex(sg[max(0, i-x)][0], sg[max(0, i-y)][1], sg[max(0, i-z)][2]);
		sg[i][1] = mex(sg[max(0, i-x)][0], -1, sg[max(0, i-z)][2]);
		sg[i][2] = mex(sg[max(0, i-x)][0], sg[max(0, i-y)][1], -1);
	}

	precom();
//	for (int i = 0; i < 100; i++) {
//		cout << sg[i][0] << ' ' << sg[i][1] << ' ' << sg[i][2] << '\n';
//	}
//	cerr << "pref loop " << pref << ' ' << loop << '\n';

	int xor_sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		xor_sum ^= get_sg(a[i]);
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		int old = get_sg(a[i]);
		xor_sum ^= old;

		if (get_sg(max(a[i]-x, 0LL), 0) == xor_sum) ans++;
		if (get_sg(max(a[i]-y, 0LL), 1) == xor_sum) ans++;
		if (get_sg(max(a[i]-z, 0LL), 2) == xor_sum) ans++;

		xor_sum ^= old;
	}

	cout << ans << '\n';
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
}