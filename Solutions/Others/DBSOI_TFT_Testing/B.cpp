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

#define MAXN 1000006
#define INF 0x3f3f3f3f
//#define MOD 998244353LL
#define MOD 1000000007LL

int n, k;
int a[MAXN];
long long ps[MAXN];

void bf() {
    for (int i = 1; i <= n; i++)
        ps[i] = ps[i-1] + a[i-1];

    vector<long long> v;
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i < j; i++) {
            v.pb(ps[j] - ps[i]);
            if (ps[j] - ps[i] < 0)
                v.pb(ps[i] - ps[j]);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
    }


    cout << v[k-1] << '\n';
}

void solve() {
    cin >> n >> k;
    n--;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<pair<long long, int> > s;
    s.insert({0, -1});

    vector<long long> v;

    for (long long i = 0, ps = 0; i < n; i++) {
        // least 100: positive
        // greatest 100: negative

        ps += a[i];

        auto it1 = s.begin();
        for (int i = 0; i < min((int)s.size(), 105); i++) {
            long long res = ps - it1 -> fi;
            if (res >= 0) {
                v.pb(res);
            }
            it1++;
        }
        auto it2 = s.rbegin();
        for (int i = 0; i < min((int)s.size(), 105); i++) {
            long long res = ps - it2 -> fi;
            if (res < 0) {
                v.pb(-res);
                v.pb(+res);
            }
            it2++;
        }

        s.insert({ps, i});

        if (v.size() > 105) {
            nth_element(v.begin(), v.begin() + 105, v.end(), [](long long x, long long y){return x > y;});
        }

//        sort(v.begin(), v.end(), [](long long x, long long y){return x > y;});

        while (v.size() > 105)
            v.pop_back();
    }

    sort(v.begin(), v.end(), [](long long x, long long y){return x > y;});

    cout << v[k-1] << '\n';
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