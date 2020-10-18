#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 25;
struct p{
    ll x;
    int s;
    int i;
} w[maxn];
bool cmp(p a,p b){
    ll sa = 1ll*a.s*a.s*a.s;
    ll sb = 1ll*b.s*b.s*b.s;
    if(b.x*sa == a.x*sb) return a.i < b.i;
    else return a.x * sb < b.x * sa;
}
int n;
int main(){
    cin >> n;
    for(int i=1;i<=n;++i){
        int S;
        ll a,b,c;
        cin >> S >> a >> b >> c;
        w[i].i = i;
        w[i].s = S;
        w[i].x = 0;
        w[i].x += 2 * (a*a*b+b*b*a+2*a*b*(S-a-b));
        w[i].x += 2 * (a*a*c+c*c*a+2*a*c*(S-a-c));
        w[i].x += 2 * (b*b*c+c*c*b+2*b*c*(S-b-c));
    }
    sort(w+1,w+n+1,cmp);
    for(int i=1;i<=n;++i){
        printf("%d ",w[i].i);
    }
    printf("\n");
    return 0;
}
