#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define MAXN 100005
#define INF 0x3f3f3f3f3f3f3f3f

void solve() {
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	long long x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	long long nx = x, ny = y;
	nx += b-a;
	ny += d-c;

	if (nx < x1 || nx > x2 || ny < y1 || ny > y2) {
		cout << "No\n";
	}
	else if (a && (b == 0) && x == x1){
		cout << "No\n";
	}
	else if (b && (a == 0) && x == x2){
		cout << "No\n";
	}
	else if (c && (d == 0) && y == y1){
		cout << "No\n";
	}
	else if (d && (c == 0) && y == y2){
		cout << "No\n";
	}
	else if (y1 == y2 and (c or d)) {
		cout << "No\n";
	}
	else if (x1 == x2 and (a or b)) {
		cout << "No\n";
	}
	else {
		cout << "Yes\n";
	}

}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

}