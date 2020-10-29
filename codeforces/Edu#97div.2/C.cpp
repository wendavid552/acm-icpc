# include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
int n;
int t[maxn];
bool used[maxn*2];
void solve(){
    memset(used,0,sizeof used);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",t+i);
    int ans = 0;
    for(int i=1;i<=n;++i){
        int l=t[i],r=t[i];
        while(used[l]&&l>0)--l;
        while(used[r])++r;
        if(l == 0){
            used[r] = 1;
            ans += r - t[i];
        }
        else{
            if(t[i]-l < r-t[i]){
                used[l] = 1;
                ans += t[i] - l;
            }
            else{
                used[r] = 1;
                ans += r - t[i];
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    int Q; scanf("%d",&Q);
    while (Q--)solve();
    return 0;
}
