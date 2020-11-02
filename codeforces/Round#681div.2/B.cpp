#include <bits/stdc++.h>
using namespace std;
//if s[x] == 1, then f[x] = a+min{f[last-segment[x]] , f[last-segment[x]] +  b * ()},注意这里可能需要考虑前面所有的seg的min，那么就是每加一个就要多一段seg,维护到目前为止的最小和新加进来的比较即可
const int maxs = 1e5+10;
int a,b;
char s[maxs];
int fs[maxs];
int f[maxs];
void solve(){
    scanf("%d%d",&a,&b);
    scanf("%s",s+1);
    int l=strlen(s+1);
    int n=0;
    int i=1; for(;i<=l;++i)if(s[i]=='1')break;
    for(;i<=l;++i){
        if(s[i]==s[i-1]){
            ++fs[n];
        }
        else{
            fs[++n]=1;
        }
    }
//    for(i=1;i<=n;++i) printf("%d ",fs[i]); printf("\n");
    
    int minlas=0;
    
    for(i=1;i<=n;++i){
        if(i&1){
        //    printf("%d\n",i);
            f[i] = a + min(f[i-1],minlas);
            minlas = min(minlas, f[i-1]);
        }
        else minlas += fs[i] * b,f[i]=f[i-1];
    }
    printf("%d\n",f[n]);
}
int main(){
    int T; scanf("%d",&T);
    while(T--) solve();
    return 0;
}
