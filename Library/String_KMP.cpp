int p[MAXN], matchTo[MAXN];
string s;
void build_prefix() { // build prefix table on s
    p[0] = 0;
    for (int i = 1, len = 0; i < s.length(); i++) {
        while (len && s[i] != s[len]) len = p[len - 1];
        p[i] = (s[i] == s[len]) ? ++len : 0;
    }
}
void match(string t) { // matchTo[i]: longest suff(t[0...i]) that matches pref(s)
    for (int i = 0, j = 0; i < t.length(); i++) {
        while (j >= s.length() || (j && t[i] != s[j])) j = p[j - 1];
        matchTo[i] = (t[i] == s[j]) ? ++j : 0;
    }
}
