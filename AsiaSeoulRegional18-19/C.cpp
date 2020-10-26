# include <cstdio>
# include <cstring>
# include <algorithm>
# include <cstdlib>
# include <cmath>
# define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxn = 1e3+10;
/*
the horizontal distance between:
r1 + d(1,2) + d(2,3) + ... + d(n-1,n) + rn-1
d(i,i+1) = 2sqrt(ri * ri+1)
*/
int n;
int r[maxn];
int t[maxn];
inline double d(int i,int j){return 2.0*sqrt(r[i]*r[j]);}
int main()
{
    scanf("%d",&n);
    fo(i,1,n){
        scanf("%d",r+i);
    }
    if(n == 1){
        printf("%.5f\n",2.0*r[1]);
        return 0;
    }
    sort(r+1,r+n+1);
    t[1] = n;
    t[2] = n-1;
    for(int i=n-2;i>0;--i){
        double mina=r[i]+d(i,t[1])-r[t[1]]; int minp=0;    //minp: insert between minp & minp+1
        for(int j=1;j<(n-i);++j){
            double a = d(i,t[j]) + d(i,t[j+1]) - d(t[j],t[j+1]);
            if(mina > a){
                mina = a;
                minp = j;
            }
        }
        double a = r[i]+d(i,t[n-i])-r[t[n-i]];
        if (mina > a){
            mina = a;
            minp = n-i;
        }
        for(int j=(n-i);j>minp;--j) swap(t[j],t[j+1]);
        t[minp+1] = i;
    }
    double ans = r[t[1]] + r[t[n]];
    fo(i,1,n-1) ans += d(i,i+1);
    printf("%.5f\n",ans);
    return 0;
}
