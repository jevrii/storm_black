// 1327G

#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define MAXN 100005
#define INF 0x3f3f3f3f3f3f3f3f

const int TOTLEN = 1005, SIGMA = 20;
int nxt_node = 1, trie[TOTLEN][SIGMA], fail[TOTLEN], nxt[TOTLEN][SIGMA];
int has_str[TOTLEN]; // bitset. Don't use __int128
// fail[s]: ending node of the proper prefix of some pattern which is the longest proper suffix of s
// has_str[s]: indexes of all words ending at s

int toInt(char c) {
	if ('a' <= c && c <= 'z') return c - 'a';
	else return c - 'A' + 26;
}

void insert(string s, int val) { // insert string[id] into the trie
	int cur = 0;
	for (char c : s) {
		if (trie[cur][toInt(c)] == -1) // no next node
			trie[cur][toInt(c)] = nxt_node++;
		cur = trie[cur][toInt(c)];
	}
	has_str[cur] += val; // str[id] can terminate at this node. ++ for count
}

void buildFail() {
	queue<int> q;
	for (int ch = 0; ch < SIGMA; ch++) // build initial edges for depth-1 nodes
		if (trie[0][ch] >= 1) {
			fail[trie[0][ch]] = 0;
			q.push(trie[0][ch]);
		}
		else trie[0][ch] = 0; // if no edge, loop back to self. modifies trie edge!
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int ch = 0; ch < SIGMA; ch++) {
			if (trie[now][ch] != -1) { // has trie edge
				int f = fail[now];
				while (trie[f][ch] == -1) // go back until node has ch as child
					f = fail[f];
				f = trie[f][ch]; // forwards 1 char, suffix fail points to this
				fail[trie[now][ch]] = f;
				has_str[trie[now][ch]] += has_str[f]; // += for count
				q.push(trie[now][ch]);
			}
		}
	}
}

int nextState(int cur, char c) { // at this node, where to go next with edge c?
	if (nxt[cur][toInt(c)] != -1) return nxt[cur][toInt(c)];
	if (trie[cur][toInt(c)] != -1)
		return nxt[cur][toInt(c)] = trie[cur][toInt(c)];
	else return nxt[cur][toInt(c)] = nextState(fail[cur], c);
}

pair<int, long long> nextState(int cur, string s) {
	long long val = 0;
	for (char c : s) {
		cur = nextState(cur, c);
		val += has_str[cur];
	}
	return mp(cur, val);
}

pair<int, long long> mem[1005][20];
long long dp[1<<16][1005];
vector<int> pos;
string s;
int n;

pair<int, long long> nextState(int cur, int used) {
	if (mem[cur][used].fi != -1) return mem[cur][used];
	string seg = s.substr(pos[used]+1, pos[used+1]-pos[used]-1);
	return mem[cur][used] = nextState(cur, seg);
}

long long dpf(int bs, int state) {
	if (dp[bs][state] != ~INF) return dp[bs][state];

	long long ret = ~INF;

	int used = __builtin_popcount(bs);
	if (pos[used] == s.length()) return 0;

	for (char c = 'a'; c <= 'n'; c++) {
		if (not (bs&(1<<(c-'a')))) {
			string seg = string(1, c);
			int nxt1, nxt2; long long add1, add2;
			tie(nxt1, add1) = nextState(state, seg);
			tie(nxt2, add2) = nextState(nxt1, used);

			ret = max(ret, add1 + add2 + dpf(bs | (1 << (c-'a')), nxt2));
		}
	}

	return dp[bs][state] = ret;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);

	memset(trie, -1, sizeof(trie)); nxt_node = 1;
	memset(has_str, 0, sizeof(has_str));
	memset(fail, -1, sizeof(fail));
	memset(nxt, -1, sizeof(nxt));

	for (int i = 0; i < 1005; i++)
		for (int j = 0; j < 20; j++)
			mem[i][j].fi = -1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string t; long long val;
		cin >> t >> val;
		insert(t, val);
	}
	buildFail();

	memset(dp, ~INF, sizeof(dp));

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '?')
			pos.pb(i);
	}
	pos.pb(s.length());


	string seg = s.substr(0, pos[0]);
	int nxt; long long add;
	tie(nxt, add) = nextState(0, seg);
	cout << add + dpf(0, nxt) << '\n';
}
