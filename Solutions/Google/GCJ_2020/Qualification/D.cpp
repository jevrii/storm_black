#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";
#define INF 0x3f3f3f3f3f3f3f3f

#define MAXN 1005
#define MOD 998244353LL

int t, b;
bool WA;

int id[20][20];
vector<int> ans[20];

int ask(int pos) {
	cout << pos << '\n';
	fflush(stdout);
	int x; cin >> x;
	return x;
}

void flip(vector<int> & v) {
	for (int i = 1; i <= 10; i++)
		v[i] ^= 1;
}

void rev(vector<int> &v) {
	reverse(v.begin() + 1, v.begin() + 1 + 10);
}

void solve() {
	int cur = 1;
	for (int r = 1; r <= b/10; r++)
		for (int c = 1; c <= 5; c++)
			id[r][c] = cur++;
	for (int r = b/10; r >= 1; r--)
		for (int c = 6; c <= 10; c++)
			id[r][c] = cur++;

	for (int r = 1; r <= b/10; r++) {
		ans[r].resize(20);
		for (int c = 1; c <= 10; c++) {
			ans[r][c] = ask(id[r][c]);
		}
	}

	// first pass: correct flip
	for (int r = 1; r <= b/10; r++) {
		int p = 1;
		for (int c = 2; c <= 5; c++) {
			if (ans[r][10-c+1] == ans[r][c]) {
				p = c;
			}
		}
		if (ans[r][p] != ask(id[r][p])) {
			flip(ans[r]);
		}
	}

	// second pass: correct reverse
	for (int r = 1; r <= b/10; r++) {
		int p = 1;
		for (int c = 2; c <= 5; c++) {
			if (ans[r][10-c+1] != ans[r][c]) {
				p = c;
			}
		}
		if (ans[r][p] != ask(id[r][p])) {
			rev(ans[r]);
		}
	}

	int need_flip = -1;

	for (int r = 1; r <= b/10; r++) {
		for (int c = 1; c <= 5; c++) {
			if (need_flip == -1 && ans[r][10-c+1] == ans[r][c]) {
				need_flip = (ans[r][c] != ask(id[r][c]));
			}
		}
	}

	if (need_flip) {
		for (int r = 1; r <= b/10; r++) {
			flip(ans[r]);
		}
	}

	int need_rev = -1;
	for (int r = 1; r <= b/10; r++) {
		for (int c = 1; c <= 5; c++) {
			if (need_rev == -1 && ans[r][10-c+1] != ans[r][c]) {
				need_rev = (ans[r][c] != ask(id[r][c]));
			}
		}
	}

	if (need_rev) {
		for (int r = 1; r <= b/10; r++) {
			rev(ans[r]);
		}
	}


	// output answer
	vector<int> output(b+1);
	for (int r = 1;  r <= b/10; r++)
		for (int c = 1; c <= 10; c++)
			output[id[r][c]] = ans[r][c];

	for (int i = 1; i <= b; i++)
		cout << output[i];
	cout << '\n';
	fflush(stdout);
	string status; cin >> status;
	if (status != "Y") {
		WA = 1;
	}
}

int main(){
//#ifdef LOCAL
//	freopen("input.txt","r",stdin);
//#endif
//	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t >> b;
	while ((not WA) and t--) {
		solve();
		if (WA) {
			return 0;
		}
	}
}