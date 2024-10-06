#include <bits/stdc++.h>
using namespace std;
int n;
#define MAXN 5005
int x[MAXN], y[MAXN];
#define pll pair<long long, long long>
#define fi first
#define se second

// eqt of straight lines

map<pair<long double, pair<long double, long double>>, long long> m;

pll frac(long long x, long long y) {
    if (x == 0 and y == 0)
        return {0, 0};
    if (x == 0)
        return {0, 1};
    if (y == 0)
        return {1, 0};

    int sgn = 1;
    if (x == 0) sgn = 0;
    if (x < 0) sgn *= -1;
    if (y < 0) sgn *= -1;

    x = abs(x);
    y = abs(y);

    long long g = __gcd(x, y);

    return {sgn*x/g, y/g};
}

bool great(pll x, pll y) {
    return (__int128)x.fi*y.se > (__int128)y.fi*x.se;
}

pair<pll, pll> f(long long x1, long long y1, long long x2, long long y2) {
//    cerr << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    // (y1 – y2)x + (x2 – x1)y + (x1y2 – x2y1)
    long double A = (y1 - y2);
    long double B = (x2 - x1);
    long double C = (x1*y2 - x2*y1);

    // perpindicular line passing through point: Bx - Ay + Ay'-Bx' = 0
    // put (x', y') = (x1, y1), y = 0
    // Bx - A*0 + A*y1-B*x1 = 0

    long double p1 = -(A*y1-B*x1)/ B;
    long double p2 = -(A*y2-B*x2)/ B;

//    cerr << p1.fi << ' ' << p1.se << ' ' << p2.fi << ' ' << p2.se << '\n';

    if (p1 > p2)
        swap(p1, p2);

    return {p1, p2};
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (x[i] < x[j] && y[i] <= y[j]) {
                auto p = f(x[i], y[i], x[j], y[j]);
                long double  slope = (y[i]-y[j])/(x[i]-x[j]);
                m[{slope, p}]++;
            }
        }
    long long ans = 0;
    for (auto op : m) {
//        cout << op.fi.fi.fi << ' ' << op.fi.se.fi << ' ' << op.se << '\n';
        ans += op.se*(op.se-1)/2;
    }
    cout << ans << '\n';
}