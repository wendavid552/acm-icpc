#include<cstdio>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define LL long long
using namespace std;
const int maxn = 110;
int n,m;
int a[maxn][maxn];
inline int
abs(int x)
{
    return x>0?x:(-x);
}
void
solve()
{
    scanf("%d%d",&n,&m);
    fo(i,1,n)fo(j,1,m){
        scanf("%d",&a[i][j]);
    }
    LL ans = 0;
    fo(i,1,n/2+1)fo(j,1,m/2+1){
        if(i>=n-i+1){
            if(j>=m-j+1){
                continue;
            }
            else{
                ans += abs(a[i][j]-a[i][m-j+1]);
            }
        }
        else{
            if(j==m-j+1){
                ans += abs(a[i][j]-a[n-i+1][j]);
            }
            else{
                int t[4];
                t[0]=a[i][j],t[1]=a[i][m-j+1],t[2]=a[n-i+1][j],t[3]=a[n-i+1][m-j+1];
                sort(t+0,t+4);
                ans +=  t[3]-t[0] + t[2]-t[1];
            }
        }
    }
    cout << ans '\n';
}

int
main()
{
    int T; scanf("%d",&T);
    for(int kase=1;kase<=T;++kase)solve();
    return 0;
}
