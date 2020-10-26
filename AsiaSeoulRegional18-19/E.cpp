#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define eps 0.001
using namespace std;
const int maxn = 300000+10;
pii dd[maxn];
ll d[maxn];
int n;
bool check(ll e){
    int i = 1;
    for(;i<=n;++i){
        if(d[i] > e){
            break;
        }
    }
    if(i>n)return 1;
    ll Min=d[i],Max = d[i];
    ll L1=d[i];
    for(;i<=n;++i){
        Min=min(Min,d[i]);
        Max=max(Max,d[i]);
        if(Max - (Max+Min)/2 > e){
            break;
        }
        L1 = (Min + Max) / 2;
    }
    
    if(i>n) return 1;
    
    ll L2;
    Min = Max = d[i];
    for(;i<=n;++i){
        Min = min(Min,d[i]);
        Max = max(Max,d[i]);
        if(Max - (Max+Min)/2 > e){
            break;
        }
        L2 = (Min + Max) / 2;
        //Is it better for : max((Min+Max)/2,Min+e);  ??
        //So as L1?
    }
    if(i<=n)return 0;
    else    return L1 <= L2;
}
int main(){
    int bas = 0;
    scanf("%d",&n);
    fo(i,1,n){
        scanf("%d %d",&dd[i].fi,&dd[i].se);
    }
    sort(dd+1,dd+n+1);
    int j=0;
    fo(i,1,n){
        if(dd[i].fi == 0) bas=max(bas,dd[i].se);
        else d[++j] = dd[i].se*10LL;
    }
    n = j;
    ll l=0,r=(ll)1e11;
    ll res = -1;
    while(r>=l){
        ll mid = (l+r)>>1;
        if(check(mid)){
            res = mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    res = max(res,10LL * bas);
    printf("%lld.%lld\n",res/10,res%10);
    return 0;
}
