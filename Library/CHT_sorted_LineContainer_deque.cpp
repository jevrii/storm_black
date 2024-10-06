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

    void add(ll m, ll p, ll idx){
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

/*
 * Reference: https://oj.uz/submission/138217
 * https://codeforces.com/blog/entry/63823
 *
 */