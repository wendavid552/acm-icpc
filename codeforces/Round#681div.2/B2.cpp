#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int a,b;
char s[maxn];
int n;
int fs[maxn];
int f[maxn];
void solve(){
    scanf("%d%d",&a,&b);
    scanf("%s",s+1);
    int l=strlen(s+1);
    n=0;
    int i;
    for(i=1;i<=l;++i)if(s[i]!='0')break;
    for(;i<=l;++i){
        if(s[i]==s[i-1]){
            ++fs[n];
        }
        else{
            fs[++n]=1;
        }
    }
    for(i=1;i<=n;++i){
        if(i%2==1){
            int minlas = f[i-1];
            int mins = 0;
            for(int j=i-1;j>0;--j){
                if(j%2==1) minlas=min(minlas,f[j-1]+mins);
                else mins += b * fs[j];
            }
            f[i] = minlas + a;
        }
        else{
            f[i]=f[i-1];
        }
    }
    printf("%d\n",f[n]);
}
int main(){
    int T; scanf("%d",&T);
    while(T--) solve();
    return 0;
}
