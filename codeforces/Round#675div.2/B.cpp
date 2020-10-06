#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
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
    long long ans = 0;
    fo(i,1,n)fo(j,1,m){
        if(i==n-i+1){
            if(j==m-j+1){
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
                
            }
        }
    }
}

int
main()
{
    int T; scanf("%d",&T);
    for(int kase=1;kase<=T;++kase)solve();
    return 0;
}
