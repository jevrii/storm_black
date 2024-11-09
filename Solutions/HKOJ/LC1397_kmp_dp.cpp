#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

string mini, bad;

int MOD = 1000000007;
int dp[505][2][55];
int p[55];

int get_nxt(int cur_matched, char nxt) {
    while (cur_matched && nxt != bad[cur_matched])
        cur_matched = p[cur_matched-1];
    if (nxt == bad[cur_matched]) return cur_matched + 1;
    else return 0;
}

int dpf(int pos, bool bounded, int mb) {
    if (mb == bad.length()) return 0;
    if (pos == mini.length()) return 1;
    if (dp[pos][bounded][mb] != -1) return dp[pos][bounded][mb];
    int ret = 0;

    if (bounded) {
        for (int nxt = 'a'; nxt < mini[pos]; nxt++) {
            (ret += dpf(pos + 1, 0, get_nxt(mb, nxt))) %= MOD;
        }
        int nxt = mini[pos];
        (ret += dpf(pos + 1, 1, get_nxt(mb, nxt))) %= MOD;
    }
    else {
        for (int nxt = 'a'; nxt <= 'z'; nxt++) {
            (ret += dpf(pos + 1, 0, get_nxt(mb, nxt))) %= MOD;
        }
    }

    return dp[pos][bounded][mb] = ret;
}

void build_prefix(string s) { // build prefix table on s
    p[0] = 0;
    for (int i = 1, len = 0; i < s.length(); i++) {
        while (len && s[i] != s[len]) len = p[len - 1];
        p[i] = (s[i] == s[len]) ? ++len : 0;
    }
}

int findGoodStrings(int n, string s1, string s2, string evil) {
    if (s1 > s2) return 0;

    build_prefix(evil);

    mini = s1; bad = evil;
    memset(dp, -1, sizeof(dp));
    int a1 = dpf(0, 1, 0);

    mini = s2;
    memset(dp, -1, sizeof(dp));
    int a2 = dpf(0,1,0);

    return (a2-a1+MOD+(s1.find(evil)==string::npos))%MOD;
}

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif
    // https://leetcode.com/contest/weekly-contest-182/problems/find-all-good-strings/
    /*
     * Given the strings s1 and s2 of size n, and the string evil. Return the number of good strings.

        A good string has size n, it is alphabetically greater than or equal to s1,
        it is alphabetically smaller than or equal to s2,
        and it does not contain the string evil as a substring. Since the answer can be a huge number,
        return this modulo 10^9 + 7.
     *
     */

    ios_base::sync_with_stdio(0); cin.tie(0);

    cout << findGoodStrings(2,"aaa","azz","ab");

}
