# include <bits/stdc++.h>
# define ll long long
using namespace std;
int n;
const int maxn = 2e5+10;
int a[maxn],b[maxn];
bool judge(ll t){
    ll s = 0;
    for(int i=1;i<=n;++i){
        if(a[i] > t) s+=b[i];
    }
    return s <= t;
}
void solve(){
    scanf("%d",&n);
    ll s = 0;
    for(int i=1;i<=n;++i) scanf("%d",a+i);
    for(int i=1;i<=n;++i) scanf("%d",b+i),s+=b[i];
    
    ll l=0,r=s,res = 0;
    while(l+1<r){
        ll m = (l+r) >>1;
//        cout << l << ' ' << r << ' '  << m << endl;
        if(judge(m))r=m,res=m;
        else l=m;
    }
    if(judge(l)) res = l;
    else res = r;
    cout << res << '\n';
}
int main(){
    int T; scanf("%d",&T);
    while(T--) solve();
    return 0;
}

