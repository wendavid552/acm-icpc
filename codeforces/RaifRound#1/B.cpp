#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxn = 300000+10;
char s[maxn];
int n;
void solve(){
    scanf("%d",&n);
    scanf("%s",s+1);
    //>
    bool tag1 = 0,tag2 = 0;
    fo(i,1,n){
        if(s[i]=='<')tag1=1;
        if(s[i]=='>')tag2=1;
    }
    if(!tag1 || !tag2){ printf("%d\n",n); return; }
    int res = 0;
    fo(i,1,n){
        if(s[i]=='-'){
            int j;
            for(j=i;j<=n;++j){
                if(s[j]!='-')break;
            }
            res += j-i+1;
            i=j-1;
        }
    }
    if(s[1] == '-' && s[n] == '-') --res;
    printf("%d\n",res);
}
int main(){
    int T; scanf("%d",&T);
    while (T--)solve();
    return 0;
}
