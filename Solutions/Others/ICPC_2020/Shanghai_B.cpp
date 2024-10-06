#include <bits/stdc++.h>
using namespace std;

string a[1005], b[1005];
char aa[1005][1005],aa2[1005][1005],ans[1005][1005];
int bb[1005][1005],cc[1005][1005];
int n, m;
bool find(){
    int pp=0,pp2=0;
    for (int i=0;i<n;i++){
        for(int o=0;o<m;o++){
            if (ans[i][o]==aa[i][o]) {
                pp += 1;
            }
            else{
                pp2+=1;
            }

        }

    }
    if (pp>pp2)
        return true;
    else
        return false;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;

    for(int i=0;i<n;i++){

        for(int k =0;k<m;k++){
            cin>>aa[i][k];

        }
    }


    for(int i=0;i<n;i++){

        for(int k =0;k<m;k++){
            cin>>ans[i][k];

        }
    }
    for(int i=0;i<n;i++){

        for(int k =0;k<m;k++){
            if (aa[i][k]=='X')
                aa2[i][k] ='.';
            else
                aa2[i][k] ='X';

        }
    }
    if (find()){

        for(int i=0;i<n;i++){

            for(int k =0;k<m;k++){
                cout<<aa[i][k];
            }
            cout<<endl;
        }

    }
    else{

        for(int i=0;i<n;i++){

            for(int k =0;k<m;k++){
                cout<<aa2[i][k];
            }
            cout<<endl;
        }
    }

}