#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 100005
//#define MOD 998244353LL
#define MOD 1000000007LL

#define MAXN 100005

int dp[65][65][65][2]; // 2, 3, 4, >=5
int nxt[65][65][65][2]; // 2, 3, 4, >=5
int n;

int calc(int n) {
//    cin >> n;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    for (int cur = 2; cur <= n; cur++) {
        memset(nxt, 0, sizeof(nxt));

        for (int l2 = 0; l2 <= cur-1; (l2 == 0 ? l2 = 2 : l2++))
            for (int l3 = 0; l3 <= cur-1; (l3 == 0 ? l3 = 3 : l3++))
                for (int l4 = 0; l4 <= cur-1; (l4 == 0 ? l4 = 4 : l4++))
                    for (int l5 = 0; l5 <= (cur-1 >= 5 ? 1 : 0); l5++){
                        if (l5 and not l4) continue;
                        if (l4 and not l3) continue;
                        if (l3 and not l2) continue;

                        for (int pos = 0; pos <= cur-1; pos++) { // insert after pos-th element
                            int n2, n3, n4, n5;
                            if (pos == 0) { // adding at head shifts everything by 1
                                n2 = l2, n3 = l3, n4 = l4, n5 = l5;
                                if (l2) n2++; // shift by 1 if the LIS exists
                                if (l3) n3++; // shift by 1 if the LIS exists
                                if (l4) n4++; // shift by 1 if the LIS exists
                                (nxt[n2][n3][n4][n5] += dp[l2][l3][l4][l5]) %= MOD;
                            }
                            else {
                                n2 = l2+(pos<l2), n3 = l3+(pos<l3), n4 = l4+(pos<l4), n5 = l5;
                                if (not l2 or pos+1 < l2+(pos<l2)) n2 = pos+1;
                                if (l2 and pos >= l2) {
                                    if (not l3 or pos+1 < l3+(pos<l3)) n3 = pos+1;
                                }
                                if (l3 and pos >= l3) {
                                    if (not l4 or pos+1 < l4+(pos<l4)) n4 = pos+1;
                                }
                                if (l4 and pos >= l4) {
                                    n5 = 1;
                                }
                                (nxt[n2][n3][n4][n5] += dp[l2][l3][l4][l5]) %= MOD;
                            }
//                cerr << "cur " << cur << " pos " << pos << " l: " << l2 << ' ' << l3 << ' ' << l4 << ' ' << l5 << '\n';
//                cerr << "cur " << cur << " pos " << pos << " n: " << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << " -> " << nxt[n2][n3][n4][n5] << '\n';
                        }
                    }
        memcpy(dp, nxt, sizeof(dp));
    }

    int ans = 0;
    for (int l2 = 0; l2 <= n; l2++)
        for (int l3 = 0; l3 <= n; l3++)
            for (int l4 = 0; l4 <= n; l4++)
                for (int l5 = 0; l5 <= 1; l5++) {
                    if (l5 or (not l3 and not l4)) {
                        (ans += dp[l2][l3][l4][l5]) %= MOD;
                    }
                }
    return ans;
//    cout << ans << '\n';
}

vector<int> v = {0, 1,2,5,14,43,158,887,8426,105934,1454908,20656898,301100908,521777789,289343984,495446014,811706387,657617710,990882204,862558545,763747093,742968120,791166461,951251286,459580785,681375227,313091820,622009779,171901489,901512825,916148230,226068491,177757096,246820958,46174783,157861419,136621777,261246501,648066213,125907608,597077342,85501579,856037975,647960666,648538327,948180100,292165921,205474554,841039408,156228043,23141365,962403503,997488507,645949162,261165441,425762728,339484252,839771757,614287131,409981376,383236309};

void solve() {
    int n; cin >> n;
    cout << v[n] << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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