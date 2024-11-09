#include <bits/stdc++.h>
using namespace std;
int n;
long double ans = 0;
string s;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        if (i == 0) {
            ans = stod(input.substr(1));
        }
        else
            s += input;
    }
    long double bpm, val;
    queue<char> q;
    for (char &c : s) {
        if (c == '(') {
            c = ' ';
            q.push('b');
        }
        if (c == '{') {
            c = ' ';
            q.push('v');
        }
        if (c == ')') c = ' ';
        if (c == '}') c = ' ';
    }
    stringstream ss(s);
    bool in_bracket = 0;
    while (ss >> s) {
        if (s.back() != ',') {
            char c = q.front(); q.pop();

            if (c == 'b') {
                bpm = stod(s);
            }
            else if (c == 'v') {
                val = stod(s);
            }
        }
        else {
//            cout << "s " << s << '\n';
            for (int i = 0; i < (int)s.size(); i++) {
                if (not in_bracket && (s[i] == '[' || isdigit(s[i]) || s[i] == ',' )) {
//                    cout << i << ' ' << s.size() << ' ' << s[i] << '\n';
                    ans += 240.0/(bpm*val);
                }
                if (s[i] == '[') {
                    in_bracket = 1;
                }
                else if (isdigit(s[i])) {
                    if (s[i+1] == ']') {
                        in_bracket = 0;
                        i++;
                    }
                    i++;
                }
            }
        }
    }

    cout << fixed << setprecision(12) << ans << '\n';
}