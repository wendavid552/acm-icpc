# include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
struct point{
    int x,y;
} p[maxn];
int n;
struct frac{
    int x,y;    //x/y Here
    frac(){}
    frac(int x,int y):x(x),y(y){}
    bool operator==(const frac& a){return x==a.x&&y==a.y;}
} e[maxn*2];
inline int qread()
{
    int x=0;char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
    return x;
}
inline int sq(int x){return x*x;}
int f[maxn];
void solve(){
    n=qread();
    for(int i=1;i<=n;++i)p[i].x=qread(),p[i].y=qread();
    p[n+1]=p[1];
    for(int i=1;i<=n;++i){
        e[i*2-1]=frac(sq(p[i+1].x-p[i].x)+sq(p[i].y*p[i].y),1);
        e[i*2]=frac(p[i+1].y-p[i].y,p[i+1].x-p[i].x);
    }
    for(int i=1;i<=n+n;++i)
        e[i+n+n]=e[i];
    e[0]=edge(0,0);
    e[(n<<2)+1]=edge(1,0);  //1 div 0, for fun, haha
    memset(f,0,sizeof f);
    for(int r=0,p=0,i=1;i<=(n<<2);++i){
        if(r>i)f[i]=min(r-i,f[p+p-i];
        else f[i]=1;
        while(e[i-f[i]]==e[i+f[i]])++f[i];
        if(i+f[i]>r)r=i+f[i],p=i;
    }
    int ans = 0;
    for(int i=n+1;i<=n*3;++i)if(f[i]>n)++ans;
    printf("%d\n",ans>>1);
}
int main()
{
    int T=qread();
    while(T--)solve();
   return 0;
}
