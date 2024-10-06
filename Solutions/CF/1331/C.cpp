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

	int x;
	cin >> x;
	string a = bitset<6>(x).to_string();
	auto b = string(6, '0');
	b[0] = a[0];
	b[1] = a[5];
	b[2] = a[3];
	b[3] = a[2];
	b[4] = a[4];
	b[5] = a[1];

//	cout << b << '\n';
	reverse(b.begin(), b.end());
	int ans = 0;
	for (int i = 0; i < 6; i++) {
		if (b[i] == '1') {
			ans += (1 << i);
		}
	}
	cout << ans << '\n';

//	cout << bitset<6>(5).to_string() << '\n';
//	cout << bitset<6>(24).to_string() << '\n';
//	cout << bitset<6>(35).to_string() << '\n';
//	cout << bitset<6>(50).to_string() << '\n';
//	cout << bitset<6>(2).to_string() << '\n';
//	cout << bitset<6>(2).to_string() << '\n';



//	cout << b << '\n';

}
