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
#define MAXN 100005
#define MOD 998244353LL

vector<long long> a[3];
int na, nb, nc;

#define sq(x) ((x)*(x))

void solve() {
    cin >> na >> nb >> nc;
    a[0].resize(na);
    a[1].resize(nb);
    a[2].resize(nc);
    for (int i = 0; i < na; i++) cin >> a[0][i];
    for (int i = 0; i < nb; i++) cin >> a[1][i];
    for (int i = 0; i < nc; i++) cin >> a[2][i];
    for (int i = 0; i < 3; i++) sort(a[i].begin(), a[i].end());
    int gen[] = {0, 1, 2};
    long long ans = LLONG_MAX;

    do {
        for (long long y : a[gen[1]]) {
            auto it1 = lower_bound(a[gen[0]].begin(), a[gen[0]].end(), y);
            if (it1 != a[gen[0]].end()) {
                long long x = *it1;
                auto it2 = upper_bound(a[gen[2]].begin(), a[gen[2]].end(), y);
                if (it2 != a[gen[2]].begin()) {
                    it2--;
                    long long z = *it2;
                    ans = min(ans, sq(x-y)+sq(y-z)+sq(x-z));

//                    cout << x << ' ' << y << ' ' << z << '\n';
                }
            }
        }
    } while (next_permutation(gen, gen+3));

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
    cin >> t;
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}