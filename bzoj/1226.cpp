# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# define LL long long
# define fi first
# define se second
# define mp make_pair
# define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int INF = 1<<30;
const int maxn = 1e3+10;
/*
f[i][j][k] 前i-1个人都吃过，j表示i和后bi个人拿饭状态，k表示前一个拿饭的人[-8,7] ->[16]
f[i][j][k] -> f[i+1][j>>1][?]
*/
int n;
int t[maxn];
int b[maxn];
inline int calc(int x,int y)
{
    return (x|y) - (x&y);
}
int f[maxn][(1<<8)+10][20];
void solve()
{
    memset(f,127,sizeof f);
    scanf("%d",&n);
    fo(i,1,n)scanf("%d%d",t+i,b+i);
    f[1][0][7] = 0;
    fo(i,1,n){
        fo(j,0,(1<<8)-1){
            fo(k,-8,7){
                if(f[i][j][k+8] != INF){
                    if(j&1) f[i+1][j>>1][k+7] = min(f[i+1][j>>1][k+7],f[i][j][k+8]);
                    else
                    {
                        int p = INF;
                        fo(u,0,7){
                            if(!((j>>u)&1)){
                                if(i+u>p) break;
                                p=min(p,i+u+b[i+u]);
                                f[i][j|(1<<u)][u+8] = min(f[i][j|(1<<u)][u+8],f[i][j][k+8]+(i+k?(t[i+k]^t[i+u]) : 0));
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = INF;
    fo(k,-8,-1) ans = min(ans,f[n+1][0][k+8]);
    printf("%d\n",ans);
}
int main()
{
    int T; scanf("%d",&T);
    for(int kase=1;kase<=T;++kase) solve();
    return 0;
}
