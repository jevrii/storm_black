/*
 * Z[i] of Z array stores length of the longest substring starting from str[i],
 * which is also a prefix of str.
 * The first entry of Z array is meaningless as complete string is always prefix of itself.
 */

vector<int> build_z_array(string s)
{
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, r = 0, p = 0; i < n; i++) {
        if (r > i) {
            int j = i - p;
            z[i] = min(z[j], r - i);
        }
        while ((i + z[i] < n) && (s[z[i]] == s[i + z[i]])) {
            ++z[i];
        }

        if (i + z[i] > r) {
            p = i;
            r = i + z[i];
        }
    }
    return z;
}
