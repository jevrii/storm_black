#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define MAXN 100005

bool Q;
typedef long long ll;
struct line {
    ll m, c,idx;
    ll eval(ll x) { return m * x + c; }
#define ld long double
    ld intersectX(line l) {
        if(l.m == m)
            return LLONG_MAX;
        assert(l.m != m);
        return (ld) (c - l.c) / (l.m - m);
    }
};

struct LineContainer{
    // for maximum + m increasing x increasing
    // for minimum + m decreasing x increasing, use -m , -x, -ret

    deque<line> dq;

    void add(ll m,ll p,ll idx){
        line cur = {m,p,idx};
        while (dq.size() >= 2 && dq[dq.size()-1].intersectX(cur) <= dq[dq.size()-2].intersectX(dq[dq.size()-1]))
            dq.pop_back();
        dq.push_back(cur);
    }

    pair<ll,ll> query(ll x){
        while (dq.size() >= 2 && dq[0].eval(x) <= dq[1].eval(x))
            dq.pop_front();

        return make_pair(dq[0].eval(x),dq[0].idx);
    }
};

int n;
int a[MAXN], b[MAXN];
ll dp[MAXN];

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    LineContainer s;
    dp[1] = 0;
    s.add(b[1], dp[1], -1);

    for (int i = 2; i <= n; i++) {
        dp[i] = s.query(a[i]).fi;
        s.add(b[i], dp[i], -1);
    }

    cout << dp[n] << '\n';




}

/*
 *
 * dp[i] = (ps[i]-ps[j-1]) * sum(0,j-1) + dp[j-1][k-1]
 * dp[i] = ps[i]*ps[j-1] + (dp[j-1][k-1] - ps[j-1]*ps[j-1])
 *
 *
 */
