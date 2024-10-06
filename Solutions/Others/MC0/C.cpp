#include <bits/stdc++.h>
using namespace std;
int n;
long long r, c;
long long a[500005];

void work_nothing() {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum < 0) {
            return;
        }
    }
    if (sum <= 0){
        return;
    }
    cout << 0 << '\n';
    exit(0);
}

long long cancel_no_sort() {
    priority_queue<long long> q;
    long long sum = 0;
    long long ret = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0)
            sum += a[i];
        else {
            sum += a[i];
            q.push(-a[i]);
        }
        if (sum < 0) {
            sum += q.top();
            q.pop();
            ret += c;
        }
    }
    if (sum <= 0)
        ret += c;
    return ret;
}

long long sort_and_pop() {
    sort(a, a+n);
    reverse(a, a+n);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum <= 0)
            return r+c*(n-i);
    }
    return r;
}

int main() {
    cin >> n >> r >> c;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (all_of(a, a+n, [](int x){
        return x<0;
    })) {
        cout << -1 << '\n';
        return 0;
    }

    work_nothing();

    long long r1 = cancel_no_sort();
    long long r2 = sort_and_pop();

    cout << min(r1, r2) << '\n';
}