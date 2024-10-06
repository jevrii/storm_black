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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 2000006
#define MOD 998244353LL

#define MX 10000007
int min_prime_factor[MX + 5];
vector<int> v[MAXN];
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

void solve() {
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        for (long long y = 2; y*y <= x; y++) {
            if (x%y == 0) {
                int cnt = 0;
                while (x%y == 0) {
                    x /= y;
                    cnt++;
                }
                v[y].pb(cnt);
            }
        }
        if (x > 0)
            v[x].pb(1);
    }

    long long ans = 1;
    for (int i = 0; i < MAXN; i++) {
        if (v[i].size() <= n-2) continue;
        if (n-v[i].size() == 1) v[i].pb(0);
        sort(v[i].begin(), v[i].end());
        ans *= powl((long long)i, v[i][1]);
    }

    cout << ans << '\n';


}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    auto start_time = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;
    sieve();
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}