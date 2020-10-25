# include <bits/stdc++.h>
# define fo(i,a,b) for(int i=(a);i<=(b);++i)
# define pb push_back
using namespace std;
const int maxn = 3e5+10;
int n,m;
vector<int> g[maxn];
bool vis[maxn];
int low[maxn],dfn[maxn];
int subN[maxn];
bool isSPF[maxn];
int dep[maxn];
int root;
void dfs(int x)
{
    vis[x] = 1;
    low[x] = dfn[x] = dep[x];
    fo(i,0,g[x].size()-1){
        int v=g[x][i];
        if(!vis[v]){
            if(x==root)subN[x]++;
            dep[v] = dep[x] + 1;
            if(x!=root) low[x]=min(low[x],low[v]);
            if(low[v] >= dfn[x] && x!=1){
                isSPF[x]=1;
                subN[x]++;
            }
        }
        else low[x]=min(low[x],dfn[v]);
    }
}
int fa[maxn];
int find(int x){
    int f = x;
    while(fa[f] != f){
        f = fa[f];
    }
    int ff=fa[x];
    while(ff!=f){
        ff = fa[x];
        fa[x] = f;
        x = ff;
    }
    return f;
}
bool fvis[maxn];
int siz[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    fo(i,1,n) fa[i] = i,siz[i]=1;
    fo(i,1,m){
        int u,v; scanf("%d%d",&u,&v);
        g[u].pb(v);
        g[v].pb(u);
        int x=find(u),y=find(v);
        fa[x] = y;
        siz[y]+=siz[x];
    }
    int cnt = 0;
    fo(i,1,n){
        int x=find(i);
        if(!fvis[x]){
            fvis[x]=1;
            cnt++;
        }
    }
    dep[1] = 1;
    root = n / 2 + 1;
    dfs(root);
    if(subN[root]>1){
        isSPF[root]=1;
        subN[root]--;
    }
    fo(i,1,n){
        if(isSPF[i]){
            printf("%d ",cnt+subN[i]);
        }
        else if (siz[find(i)]!=1){
            printf("%d ",cnt);
        }
        else printf("%d ",cnt-1);
    }
    printf("\n");
    return 0;
}