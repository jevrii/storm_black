#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define MAXN 100005
#define INF 0x3f3f3f3f3f3f3f3f

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s; cin >> s;
	cout << (s.back()-'0')%2 << '\n';

}
