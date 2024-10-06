#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";
#define INF 0x3f3f3f3f3f3f3f3f

#define MAXN 500005
#define MOD 998244353LL

#define MX 10000007
int min_prime_factor[MX + 5];
vector<int> primes;

void sieve(){
	for (long long i = 2; i <= MX; i++) {
		if(!min_prime_factor[i]) min_prime_factor[i] = i, primes.pb(i);
		for (long long j = 0; i * primes[j] <= MX; j++){
			min_prime_factor[i * primes[j]] = primes[j];
			if(i % primes[j] == 0) break;
		}
	}
}
vector<int> factorize(int x){
	vector<int> a;
	for(int j = x; j > 1;)
		a.pb(min_prime_factor[j]), j /= min_prime_factor[j];
	return a;
}

bool vis[MAXN];
vector<int> ans;

int num_prime_factors[MAXN];

void solve() {
	priority_queue<pii, vector<pii>, greater<pii> > q;
	int n;
	cin >> n;
	q.push(mp(1, 1));
	while (q.size()) {
		int g, v;
//		cerr << "node " << v << '\n';
		tie(g, v) = q.top();
		q.pop();
		ans.pb(g);

		for (int pr : primes) {
			if (pr * v > n) break;
			if (not vis[pr * v]) {
				if (!--num_prime_factors[pr*v]) {
					q.push(mp(v, pr*v));
					vis[pr*v] = 1;
//					cerr << v << ' ' << "push " << pr*v << '\n';
				}
			}
		}
	}
	for (int i = 1; i < ans.size(); i++)
		cout << ans[i] << " \n"[i+1==ans.size()];
}

void init() {
	sieve();
	for (int pr : primes) {
		for (int i = pr; i < MAXN; i += pr) {
			num_prime_factors[i]++;
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	init();

	int t = 1;
	while (t--) {
		solve();
	}
}