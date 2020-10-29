#include<bits/stdc++.h>
using namespace std;
const int inf=0x7f7f7f7f;
const int N=1010;//点 
const int M=1e5+10;//边
 
struct Edge
{
	int to,w,cost,next;
}edge[M];
 
int head[N],cnt;
 
void addedge(int u,int v,int w,int cost)
{
	edge[cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].cost=cost;
	edge[cnt].next=head[u];
	head[u]=cnt++;
	edge[cnt].to=u;
	edge[cnt].w=0;
	edge[cnt].cost=-cost;
	edge[cnt].next=head[v];
	head[v]=cnt++;
}
 
int d[N],incf[N],pre[N];
 
bool vis[N];
 
bool spfa(int s,int t)
{
	memset(d,inf,sizeof(d));
	memset(vis,false,sizeof(vis));
    memset(pre,-1,sizeof(pre));
	queue<int>q;
	q.push(s);
	vis[s]=true;
	incf[s]=inf;
	d[s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].to;
			int w=edge[i].w;
			int cost=edge[i].cost;
			if(!w)
				continue;
			if(d[v]>d[u]+cost)
			{
				d[v]=d[u]+cost;
				pre[v]=i;
				incf[v]=min(incf[u],w);
				if(!vis[v])
				{
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
	return pre[t]!=-1;
}
 
int update(int s,int t)
{
	int x=t;
    printf("Now %d to %d\n",s,t);
	while(x!=s)
	{
		int i=pre[x];
        printf("(%d,%d)\n",edge[i^1].to,edge[i].to);
		edge[i].w-=incf[t];
		edge[i^1].w+=incf[t];
		x=edge[i^1].to;
	}
	return d[t]*incf[t];
}
 
void init()
{
	memset(head,-1,sizeof(head));
	cnt=0;
}
 
int solve(int st,int ed)
{
	int ans=0;
	while(spfa(st,ed)){
		ans+=update(st,ed);
    }
	return ans;
}

int n; int t[N];
inline int _abs(int x){return x>0?x:-x;}
int main(){
    int q; scanf("%d",&q);
    while(q--){
        init();
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d",t+i);
            for(int j=1;j<=400;++j){
                addedge(t[i],200+j,1,_abs(t[i]-j));
            }
        }
        for(int i=1;i<=200;++i)addedge(0,i,1,0);
        for(int i=201;i<=600;++i)addedge(i,601,1,0);
        int ans = solve(0,601);
        printf("%d\n",ans);
    }
   return 0;
}
