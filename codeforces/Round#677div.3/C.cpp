#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxn = 3e5+10;
int n;
int a[maxn];
void solve(){
    scanf("%d",&n);
    int mx = 0;
    fo(i,1,n){
        scanf("%d",a+i);
        mx = max(mx,a[i]);
    }
    bool tag = 0;
    fo(i,1,n) if(a[i] != mx){tag = 1; break;}
    if(tag){
        int i;
        if(a[1] == mx){
            for(i=1;i<=n;++i){
                if(a[i] != mx){
                    printf("%d\n",i-1);
                    return;
                }
            }
        }
        else{
            for(i=2;i<=n;++i){
                if(a[i] == mx){
                    printf("%d\n",i);
                    return;
                }
            }
        }
    }
    else printf("%d\n",-1);
}
int main(){
    int T; scanf("%d",&T);
    fo(i,1,T) solve();
    return 0;
}
