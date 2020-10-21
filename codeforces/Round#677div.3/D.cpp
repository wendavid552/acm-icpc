#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxn = 5e3+10;
int fa[maxn];
inline int find(int x){
    return (fa[x]==x?x:fa[x] = find(fa[x]));
}
int n;
int g[maxn];
vector<pair<int,int> > P;
void solve(){
    P.clear();
    scanf("%d",&n);
    fo(i,1,n){
        scanf("%d",g+i);
    }
    fo(i,1,n) fa[i] = i;
    fo(i,1,n-1){
        bool tag = 0;
        fo(j,1,n){
            if(g[i] != g[j] && find(i)!=find(j)){
                fa[find(i)]=find(j);
                P.push_back(make_pair(i,j));
                tag = 1;
                break;
            }
        }
        if(!tag){
            printf("NO\n"); return;
        }
    }
    printf("YES\n");
    fo(i,0,n-2){
        printf("%d %d\n",P[i].first,P[i].second);
    }
}
int main(){
    int T; scanf("%d",&T);
    fo(k,1,T)solve();
    return 0;
}
