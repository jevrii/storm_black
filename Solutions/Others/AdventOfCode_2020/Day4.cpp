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

vector<string> req = {"byr:", "iyr:", "eyr:", "hgt:", "hcl:", "ecl:", "pid:"};
set<string> cols = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
//vector<string> req = {"???"};

bool btw(int a, int b, int c) {
    return a<=b and b<=c;
}

void solve() {
    string input;
    string cur;
    int ans;
    while (getline(cin, input)) {
        if (input.length() == 0) {
            bool bad = 0;
            for (string s : req) {
                if (cur.find(s) == string::npos) {
                    bad = 1;
                }
            }
            if (not bad) {
                for (char &c : cur)
                    if (c == ':') c = ' ';
                stringstream ss(cur);
                map<string, string> m;
                string _x, _y;
                while (ss >> _x >> _y) {
                    m[_x] = _y;
                }

                if (!btw(1920, stoi(m["byr"]), 2002)) bad = 1;
                if (!btw(2010, stoi(m["iyr"]), 2020)) bad = 1;
                if (!btw(2020, stoi(m["eyr"]), 2030)) bad = 1;
                if (m["hgt"].substr(m["hgt"].size()-2) == "cm") {
                    stringstream ss(m["hgt"]);
                    int x;
                    ss >> x;
                    if (!btw(150, x, 193)) bad = 1;
                }
                else {
                    stringstream ss(m["hgt"]);
                    int x;
                    ss >> x;
                    if (!btw(59, x, 76)) bad = 1;
                }
                if (!(m["pid"].size() == 9 && count_if(m["pid"].begin(), m["pid"].end(), [](char c){return isdigit(c);}))) {
//
                    bad = 1;
                }
                if (!cols.count(m["ecl"])) {
                    cout << cur << '\n';
                    bad = 1;
                }

                string hcl_ = m["hcl"].substr(1);
                if (!(m["hcl"][0] == '#' && m["hcl"].size() == 7
                      && count_if(hcl_.begin(), hcl_.end(), [](char c){return btw('0', c, '9') or btw('a', c, 'f');}))) {

                    cout << cur << '\n';
                    bad = 1;
                }

//                if (not bad)
            }
            ans += not bad;
            cur = "";
        }
        else {
            cur += input + " ";
        }
    }
    cout << ans << '\n';
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