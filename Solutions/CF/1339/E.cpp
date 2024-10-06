#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 500005
#define MOD 998244353LL

vector<long long> get(long long n) {
	vector<long long> ret;

	long long cur = 0, len = 0, rem = n;
	while (1) {
		if (cur + (1LL<<len) > n) break;
		rem -= (1LL << len);
		cur += (1LL << len);
		len += 2;
	}
	ret.pb((1LL<<len) + rem);

	long long x = ret[0] ^ (1LL << (len+1));

	for (int i = 0; i < len; i += 2) {
		if ((x & (1LL << i)) and !(x & (1LL << (i+1)))) { // 01 -> 11
			x ^= (1LL << (i+1)); // 11
		}
		else if (!(x & (1LL << i)) and (x & (1LL << (i+1)))) { // 10 -> 01
			x ^= (1LL << i); // 11
			x ^= (1LL << (i+1)); // 11
		}
		else if ((x & (1LL << i)) and (x & (1LL << (i+1)))) { // 11 -> 10
			x ^= (1LL << i); // 11
		}
	}

	ret.pb(ret[0] ^ x);
	ret.pb(x);

	return ret;
}

void solve() {
	long long n; cin >> n;
	n--;
	auto a = get(n/3);
	cout << a[n%3] << '\n';
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	int t = 1;
	cin >> t;
	for (int no = 1; no <= t; no++) {
//		cout << "Case #" << no << ": ";
		solve();
	}

}