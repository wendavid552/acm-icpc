
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
 
using namespace std;
 
const int MAX_SIZE = 1002,
          INF = 0x3f3f3f3f;
 
class Tarjan
{
public:
    vector <int> edges[MAX_SIZE];
    int low[MAX_SIZE], dfn[MAX_SIZE], root,
        maxNode, subnetsNum[MAX_SIZE];
    bool visited[MAX_SIZE], isNode[MAX_SIZE],
         isSPF[MAX_SIZE], found;
 
    void init()
    {
        int i;
        for(i = 0; i < MAX_SIZE; i++)
            edges[i].clear();
        found = false;
        memset(subnetsNum, 0, sizeof(subnetsNum));
        memset(isNode, 0, sizeof(isNode));
        memset(visited, 0, sizeof(visited));
        memset(isSPF, 0, sizeof(isSPF));
        maxNode = 0;
    }
 
    void addEdge(int u, int v)
    {
        edges[u].push_back(v);
        edges[v].push_back(u);
        maxNode = max(maxNode, max(u, v));
        isNode[u] = isNode[v] = true;
    }
 
    void dfs(int u, int depth)
    {
        visited[u] = true;
        low[u] = dfn[u] = depth;
        int i, v;
        for(i = 0; i < edges[u].size(); i++){
            v = edges[u][i];
            if(!visited[v]){
                if(u == root)
                    subnetsNum[root]++;
                dfs(v, depth + 1);
                if(u != root)
                    low[u] = min(low[u], low[v]);
                if(low[v] >= dfn[u] && u!= root){
                    isSPF[u] = true;
                    subnetsNum[u]++;
                    found = true;
                }
            }
            else
                low[u] = min(low[u], dfn[v]);
        }
    }
 
    void startDFS()
    {
        for(root = 1; root <= maxNode; root++)
            if(isNode[root])
                break;
        dfs(root, 1);
        if(subnetsNum[root] > 1){
            isSPF[root] = true;
            subnetsNum[root]--;
            found = true;
        }
    }
}G;
 
 
int main()
{
    //freopen("in.txt", "r", stdin);
 
    int u, v, i, j, kase = 1, cnt;
 
    while(1){
        G.init();
        scanf("%d", &u);
        if(0 == u)
            break;
        scanf("%d", &v);
        G.addEdge(u, v);
        while(1){
            scanf("%d", &u);
            if(0 == u)
                break;
            scanf("%d", &v);
            G.addEdge(u, v);
        }
 
        G.startDFS();
 
        printf("Network #%d\n", kase++);
        if(!G.found)
            printf("  No SPF nodes\n");
        else
            for(i = 1; i <= G.maxNode; i++)
                if(G.isSPF[i])
                    printf("  SPF node %d leaves %d subnets\n", i, G.subnetsNum[i]+1);
 
        printf("\n");
