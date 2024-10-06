/**
 * Author: Simon Lindholm, Source: kactl
 * Date: 2017-04-20
 * License: CC0
 * Source: own work
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 *  Useful for dynamic programming.
 * Time: O(\log N)
 * Status: tested
 */

bool Q;
typedef long long ll;
struct Line {
    mutable ll M, C, p;
    bool operator<(const Line& o) const {
        return Q ? p < o.p : M < o.M;
    }
};

struct LineContainer : multiset<Line> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->M == y->M) x->p = x->C > y->C ? inf : -inf;
        else x->p = div(y->C - x->C, x->M - y->M);
        return x->p >= y->p;
    }
    void add(ll M, ll C) { // y = Mx+C, query max. negate M,C for min
        auto z = insert({M, C, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) { // query max. negate for min
        assert(!empty());
        Q = 1; auto l = *lower_bound({0,0,x}); Q = 0;
        return l.M * x + l.C;
    }
};


/*
 * https://codeforces.com/contest/319/problem/C
 * https://judge.hkoi.org/task/M1863
 * https://judge.hkoi.org/task/M1643
 *
 */