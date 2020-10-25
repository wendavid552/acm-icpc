# include <bits/stdc++.h>
# define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxn = 2010;
const int maxm = 2010;
int T[maxn][maxm];
int M[maxn][maxm];
int n,m;
inline int lowbit(int x){return x&(-x);}
void add(int x,int y,int val){
    // printf("GET %d %d\n",x,y);
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=m;j+=lowbit(j))
            T[i][j]+=val;
}
int get(int x,int y){
    int r = 0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))r+=T[i][j];
    return r;
}
int a,b;
/* void _VIEWALL(){
    fo(i,1,n){
        fo(j,1,m){
            printf("%d ",get(i,j));
        }
        printf("\n");
    }
    printf("\n");
} */
void solve(){
    memset(T,0,sizeof T);
    scanf("%d%d%d%d",&n,&m,&a,&b);
    // printf("a=%d,b=%d\n",a,b);
    fo(i,1,n)fo(j,1,m){
        scanf("%d",&M[i][j]);
        add(i,j,M[i][j]);
        add(i+1,j,-M[i][j]);
        add(i,j+1,-M[i][j]);
        add(i+1,j+1,M[i][j]);
    }

    fo(i,1,n)fo(j,1,m){
        int x = get(i,j);
        // _VIEWALL();
        if(x < 0 || (x > 0 && (i+a-1 > n || j+b-1 > m))){
            printf("QAQ\n");
            return;
        }
        else{
            // printf("COVER to(%d,%d)\n",i+a-1,j+b-1);
            add(i,j,-x);
            add(i,j+b,x);
            add(i+a,j,x);
            add(i+a,j+b,-x);
            // printf("NOW AFTER%d\n",get(i,j));
        }
    }
    printf("^_^\n");
}
int main(){
    int T; scanf("%d",&T);
    while(T--)solve();
    return 0;
}