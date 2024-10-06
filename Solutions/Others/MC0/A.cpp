#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    if (n*m%k) {
        cout << "Impossible\n";
        return 0;
    }
    int area = n*m/k;
    for (int base = 1; base <= min(area, m); base++) {
//        cout << base << ' ' << area/base << '\n';
        if (area % base or m % base or area/base > n or n%(area/base))
            continue;
        int height = area / base;
//        cout << height << ' ' << base << '\n';

        int ch = 0;
        char st = 'A';
        while (ch < n) {
            if (st == 'A')
                st = 'X';
            else
                st = 'A';

            for (int j = 0; j < height; j++) {
                for (int i = 0; i < m/base; i++)
                    cout << string(base, st+i%2);
                cout << '\n';
            }
            ch += height;
        }

        return 0;
    }
}