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

#define MAXN 300005
#define INF 0x3f3f3f3f3f3f3f3f
//#define MOD 998244353LL
#define MOD 1000000007LL

#define MX 2000006
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

int a[MAXN];

void solve() {
    int n;
    cin >> n;
    map<set<int>, int> m1, m2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vector<int> v = factorize(a[i]);
        set<int> s;
        for (int x : v) {
            if (s.count(x)) s.erase(x);
            else s.insert(x);
        }
        m1[s]++;
    }

    int mx = 0;
    for (auto op : m1)
        mx = max(mx, op.se);

    m2 = m1;
    for (auto op : m2) {
        if (op.fi.size() == 0) continue;
        if (op.se % 2 == 0) {
            set<int> s;
            m2[s] += op.se;
        }
    }
    int mx2 = 0;
    for (auto op : m2) {
        mx2 = max(mx2, op.se);
    }

    int q;
    cin >> q;
    while (q--) {
        long long t;
        cin >> t;
        if (t == 0) {
            cout << mx << '\n';
        }
        else {
            cout << mx2 << '\n';
        }
    }


//    for (int i = 1; i <= 100; i++) {
//        cout << i << ": ";
//        for (int j = i; j <= 100; j++) {
//            int l = i*j/__gcd(i,j);
//            int g = __gcd(i, j);
//            int s = sqrt(l/g);
//            if (s*s == l/g) {
//                cout << j << ' ';
//            }
//        }
//        cout << '\n';
//    }
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
    cin >> t;
    sieve();
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}