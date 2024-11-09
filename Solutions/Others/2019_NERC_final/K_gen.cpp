vector<int>p = {0,0,0,0,2,3,3,4};
set<vector<int> > s;
do {
bool ok = 1;
for (int i = 0; i < 8; i++) {
if (p[i] > i + 1) ok = 0;
}
if (p[7]==0) ok = 0;
if (ok) s.insert(p);
} while (next_permutation(p.begin(), p.end()));

int ans = 0;
vector<int> v = {0,0,0,0,2,3,3,4};
for (int x = 40320; x < 362880; x++) {
vector<int> p = {x%2, x/2%3, x/2/3%4, x/2/3/4%5, x/2/3/4/5%6, x/2/3/4/5/6%7, x/2/3/4/5/6/7%8, x/2/3/4/5/6/7/8%9};
vector<int> t = p;
sort(p.begin(), p.end());
if(p == v) {
for (int z : t) cout <<z << ' ';
cout << '\n';
ans++;
s.erase(t);
}
//        cout << x<< ' ' << x%2 << ' ' << x/2%3 << ' ' << x/2/3%4 << ' ' << x/2/3/4%5 << ' ' << x/2/3/4/5%6 << ' ' << x/2/3/4/5/6%7 << ' ' << x/2/3/4/5/6/7<< '\n';
}
cout<< ans << '\n';

for (auto p : s) {
for (int x : p) cout << x << ' ';
cout << '\n';
}