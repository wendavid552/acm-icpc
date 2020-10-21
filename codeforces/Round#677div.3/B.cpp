#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxn = 55;
int n;
int a[maxn];
void solve(){
    scanf("%d",&n);
    fo(i,1,n) scanf("%d",a+i);
    int i = 1;
    for(;i<=n;++i) if(a[i] == 1) break;
    int cnt = 0,ncnt = 0;
    for(;i<=n;++i){
        if(a[i] == 1){
            ncnt = cnt;
        }
        else{
            cnt++;
        }
    }
    printf("%d\n",ncnt);
}
int main(){
    int T; scanf("%d",&T);
    fo(i,1,T) solve();
    return 0;
}
