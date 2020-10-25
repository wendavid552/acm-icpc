# include <bits/stdc++.h>
# define fo(i,a,b) for(int i=(a);i<=(b);++i)
# define pb push_back
using namespace std;
const int maxn = 3e5+10;
int n,m;
vector<int> g[maxn];
int vis[maxn];
int low[maxn],dfn[maxn];
int subN[maxn];
bool isSPF[maxn];
int sta[maxn];
int dep[maxn];
int stai[maxn];
int p = 0;
bool dfsed[maxn];
void dfs()
{
    dep[1] = 1;
    sta[++p] = 1;
    while(p > 0){
        int x = sta[p];
        if(!vis[x]){
            low[x] = dfn[x] = dep[x];
        }
        if(vis[x]){
            int v = g[x][stai[x]];
            if(x!=1) low[x]=min(low[x],low[v]);
            if(low[v] >= dfn[x] && x!=1){
                isSPF[x]=1;
                subN[x]++;
            }
        }
        vis[x]++;
        for(;stai[x]<g[x].size();stai[x]++){
            int v=g[x][stai[x]];
            if(!vis[v]){
                if(x==1)subN[x]++;
                sta[++p] = v;
                dep[v] = dep[x] + 1;
                break;
            }
            else low[x]=min(low[x],dfn[v]);
        }
        if(stai[x] == g[x].size()){
            --p;
            dfsed[x] = 1;
        }
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
    memset(stai,0,sizeof stai);
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
    dfs();
    if(subN[1]>1){
        isSPF[1]=1;
        subN[1]--;
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