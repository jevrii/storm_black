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

#define MAXN 200005
#define INF 0x3f3f3f3f3f3f3f3f
//#define MOD 998244353LL
#define MOD 1000000007LL

void solve() {
    vector<int> even, odd;
    int n;
    long long a=0, b=0;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x%2)
            odd.pb(x);
        else
            even.pb(x);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    bool alice = 1;
    while (even.size()+odd.size()) {
        if (alice) {
            if (odd.size() && even.size()) {
                if (even.back() >= odd.back()) {
                    a += even.back();
                    even.pop_back();
                }
                else {
                    odd.pop_back();
                }
            }
            else if (odd.size() && not even.size()) {
                odd.pop_back();
            }
            else if (not odd.size() && even.size()) {
                a += even.back();
                even.pop_back();
            }
        }
        else {
            if (odd.size() && even.size()) {
                if (odd.back() >= even.back()) {
                    b += odd.back();
                    odd.pop_back();
                }
                else {
                    even.pop_back();
                }
            }
            else if (odd.size() && not even.size()) {
                b += odd.back();
                odd.pop_back();
            }
            else if (not odd.size() && even.size()) {
                even.pop_back();
            }
        }

        alice = !alice;
    }

    if (a == b) {
        cout << "Tie\n";
    }
    else if (a>b) {
        cout << "Alice\n";
    }
    else {
        cout << "Bob\n";
    }

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
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}