#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize ("trapv")
using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 300005
//#define MOD 998244353LL
#define MOD 1000000007LL

#define MX 100005
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
int n;
int secret = 99874;
vector<int> secret_b(100000+1, 1);
int cnt = 0;
int ask(char type, int x) {
#ifdef LOCAL
    cnt++;
    if (type == 'A') {
        int ans = 0;
        for (int i=x; i <= 100000; i += x) {
            ans += secret_b[i];
        }
        return ans;
    }
    if (type == 'B') {
        int ans = 0;
        for (int i=x; i <= 100000; i += x) {
            ans += secret_b[i];
            if (i != secret)
                secret_b[i] = 0;
        }
        return ans;
    }
#else
    cout << type << ' ' << x << endl;
    int ret; cin >> ret;
    return ret;
#endif
}

void solve() {
    sieve();
    cin >> n;
    vector<int> b(n+1, 1);
    b[0] = 0;

    vector<int> primes_over_50000;
    for (int p : primes)
        if (p >= 50000 && p <= n)
            primes_over_50000.pb(p);

    int cur = 0;
    while (cur < primes_over_50000.size()) {
        int old_cur = cur;
        for (int i = 0; cur < primes_over_50000.size() && i < 67; i++, cur++) {
            ask('B', primes_over_50000[cur]);
            for (int x = primes_over_50000[cur]; x <= n; x += primes_over_50000[cur])
                b[x] = 0;
        }
        if (ask('A', 1) != accumulate(b.begin(), b.end(), 0)) { // cant remove??
            cur = old_cur;
            for (int i = 0; cur < primes_over_50000.size() && i < 67; i++, cur++) {
                if (ask('A', primes_over_50000[cur])) {
                    cout << "C " << primes_over_50000[cur] << endl;
                    fflush(stdout);
                    return;
                }
            }
        }
    }

    vector<int> pf;

    vector<int> primes_over_320;
    vector<int> primes_under_320;
    for (int p : primes) {
        if (p >= 320 && p < 50000 && p <= n)
            primes_over_320.pb(p);
        if (p < 320 && p <= n)
            primes_under_320.pb(p);
    }

    cur = 0;
    bool found_320 = false;
    while (cur < primes_over_320.size()) {
        int old_cur = cur;
        for (int i = 0; cur < primes_over_320.size() && i < 67; i++, cur++) {
            ask('B', primes_over_320[cur]);
            for (int x = primes_over_320[cur]; x <= n; x += primes_over_320[cur])
                b[x] = 0;
        }
        if (ask('A', 1) != accumulate(b.begin(), b.end(), 0)) { // cant remove??
            cur = old_cur;
            for (int i = 0; cur < primes_over_320.size() && i < 67; i++, cur++) {
                if (ask('A', primes_over_320[cur])) {
                    found_320 = true;
                    pf.pb(primes_over_320[cur]);
                    cerr << "found " << primes_over_320[cur] << '\n';
                    break;
                }
            }
        }
        if (found_320){
            break;
        }
    }

    cerr << cnt << '\n';

    for (int p : primes_under_320) {
        int mx = 1;
        ask('B', p);
        for (int x = p; x <= n; x *= p) {
            if (ask('A', x))
                mx = x;
        }
        pf.pb(mx);
    }

    int ans = 1;
    for (int x : pf)
        ans *= x;
    cout << "C " << ans << endl;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    auto start_time = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}