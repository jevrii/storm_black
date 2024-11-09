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

map<string, vector<pair<int, string> > > e;
map<string, long long> dp;

long long dpf(string s) {
    if (dp.count(s)) return dp[s];

    long long ret = 1;
    for (auto op : e[s]) {
        cout << op.fi << ' ' << op.se << '\n';
        ret += op.fi * dpf(op.se);
    }
    return dp[s] = ret;
}

void solve() {
    string input;
    while (getline(cin, input)) {
        stringstream ss(input);

        deque<string> q;
        string temp;
        while (ss >> temp)
            q.push_back(temp);

        string v = q[0] + " " + q[1];
        q.pop_front(); q.pop_front(); // color name
        q.pop_front(); q.pop_front(); // bags contain

        if (q[0] == "no") continue;

        while (q.size()) {
            int x = stoi(q[0]);
            q.pop_front();
            string u = q[0] + " " + q[1];
            q.pop_front(); q.pop_front(); // color name
            q.pop_front(); // bags

            e[v].pb(mp(x, u));
        }
    }

    cout << dpf("shiny gold")-1;
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