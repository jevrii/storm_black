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
struct Line {
    ll m, c, idx;
    ll eval(ll x) { return m * x + c; }

    long double intersectX(Line l) {
        if(l.m == m) return LLONG_MAX;
        return (long double) (c - l.c) / (l.m - m);
    }
};

struct LineContainer{
    // maximum, m increasing x increasing
    // for minimum, m decreasing x increasing, use -m , x

    deque<Line> dq;

    void add(ll m,ll p,ll idx){
        Line cur = {m, p, idx};
        while (dq.size() >= 2 && dq[dq.size()-1].intersectX(cur) <=
                                 dq[dq.size()-2].intersectX(dq[dq.size()-1])) // intersection point on left of old
            dq.pop_back();
        dq.push_back(cur);
    }

    pair<ll, ll> query(ll x){
        while (dq.size() >= 2 && dq[0].eval(x) <= dq[1].eval(x))
            dq.pop_front();

        return make_pair(dq[0].eval(x),dq[0].idx);
    }
};

int n, k;
int a[MAXN], ps[MAXN];

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif
//    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    partial_sum(a+1, a+1+n, ps+1);

    k++;

    LineContainer s[2];

    for (int j = 1;  j <= k; j++) {
        while (s[j%2].dq.size())
            s[j%2].dq.pop_back();

        for (int i = j; i <= n; i++) {
            long long cur;
            if (j == 1) cur = 0;
            else cur = s[(j-1)%2].query(ps[i]).fi;

            s[j%2].add(ps[i], cur - (ll)ps[i]*ps[i], -1);

            if (i == n && j == k) {
                cout << cur << '\n';
                return 0;
            }
        }
    }
}

/*
 *
 * dp[i] = (ps[i]-ps[j-1]) * sum(0,j-1) + dp[j-1][k-1]
 * dp[i] = ps[i]*ps[j-1] + (dp[j-1][k-1] - ps[j-1]*ps[j-1])
 *
 *
 */
