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

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 500005
#define MOD 998244353LL

int b[4][4] = {{4, 3, 6, 12},
			   {7, 5, 9, 15},
			   {14, 1, 11, 10},
			   {13, 8, 16, 2}};

int a[505][505];
int n;

void solve() {
	cin >> n;

	if (n <= 2) {
		cout << -1 << '\n';
	}
	else if (n == 3) {
		cout << "1 2 4\n";
		cout << "5 3 8\n";
		cout << "9 6 7\n";
	}
	else {
		int cur = 1;
		for (int r = 1; r+4 <= n; r++) {
			if ((r+1+n)%2) {
				for (int c = 1; c <= n; c++)
					a[r][c] = cur++;
			}
			else {
				for (int c = n; c >= 1; c--)
					a[r][c] = cur++;
			}
		}

		for (int c = n; c >= 5; c--) {
			if (c == 5) {
				a[n][5] = cur++;
				a[n-2][5] = cur++;
				a[n-3][5] = cur++;
				a[n-1][5] = cur++;
			}
			else {
				if (c % 2) {
					for (int r = n-4+1; r <= n; r++) {
						a[r][c] = cur++;
					}
				}
				else {
					for (int r = n; r >= n-4+1; r--) {
						a[r][c] = cur++;
					}
				}
			}
		}

		for (int r = n-4+1, x = 0; r <= n; r++, x++) {
			for (int c = 1; c <= 4; c++) {
				a[r][c] = b[x][c-1] + cur-1;
			}
		}

		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= n; c++) {
				cout << a[r][c] << ' ';
			}
			cout << '\n';
		}

	}

}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	while (t--) {
		solve();
	}
}