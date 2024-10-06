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

mt19937 rng;
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 500005
#define MOD 998244353LL

int n, d;
long long a[MAXN];

void solve() {
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    long long ans = INF;

    for (int i = 0; i < n; i++) {
        long long g = a[i];
        for (long long p = 1; p <= d; p++) { // how many pieces to cut into
//            cerr << "cut " << g << " into " << p << " pieces\n";
            priority_queue<long long, vector<long long>, greater<long long> > q;
            priority_queue<long long, vector<long long>, greater<long long> > uneven;
            q.push(p);
            for (int j = i+1; j < n; j++) {
                if (a[j]*p % g == 0) {
//                    cerr << a[j] << " generates " << a[j]*p/g << " pieces\n";
                    q.push(a[j]*p/g);
                }
                else {
                    uneven.push(a[j]*p/g);
                }
            }

            long long cur = 0, cnt = 0;
            while (q.size() && cur < d) {
                if (cur + q.top() <= d) {
                    cnt += q.top()-1;
                    cur += q.top();
                    q.pop();
                }
                else {
                    cnt += d-cur;
                    cur = d;
                    break;
                }
            }

            while (uneven.size() && cur < d) {
                if (cur + uneven.top() <= d) {
                    cnt += uneven.top();
                    cur += uneven.top();
                    uneven.pop();
                }
                else {
                    cnt += d-cur;
                    cur = d;
                    break;
                }
            }

            if (cur == d) {
//                cerr << "update ans " << cnt << '\n';
                ans = min(cnt, ans);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    for (int no = 1; no <= t; no++) {
        cout << "Case #" << no << ": ";
        solve();
    }
}