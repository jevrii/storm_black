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
#define MAXN 500005
#define MOD 998244353LL

string a[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[255], ans[20];

void work(int dig, char c) {
    c = toupper(c);
    ans[dig] = cnt[c] / count(a[dig].begin(), a[dig].end(), c);
    for (char del : a[dig]) {
        cnt[del] -= ans[dig];
    }
}

void solve() {
    string input;
    cin >> input;
    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));

    for (char c : input)
        cnt[c]++;

    work(0, 'z');
    work(8, 'g');
    work(3, 'h');
    work(2, 'w');
    work(6, 'x');
    work(4, 'u');
    work(5, 'f');
    work(7, 'v');
    work(1, 'o');
    work(9, 'n');

    for (int i = 0; i < 10; i++)
        cout << string(ans[i], i+'0');
    cout << '\n';
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
        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}