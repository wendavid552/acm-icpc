# include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
const int maxn = 2e5+10;
int pri[MAXN]; int cnt = 0;
bool vis[MAXN];
int f[MAXN];
map<int,int> S;
void init(){
    for(int i=2;i<=MAXN;++i){
        if(!vis[i]){pri[cnt++]=i; f[i]+=S[i];}
        for(int j=0;j<cnt&&i*pri[j]<=MAXN;++j){
            vis[i*pri[j]] = 1;
            f[i*pri[j]] = max(f[i*pri[j]],f[i]+S[i*pri[j]]);
        }
    }
    for(int i=MAXN+1;i<=10000000;++i){
        for(int j=0;j<7&&i*pri[j]<=10000000;++j){
            vis[i*pri[j]] = 1;
            if(i%pri[j]==0) break;
        }
    }
}
int n;
int a[maxn];
int ans[maxn];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",a+i),S[a[i]]++;
    sort(a+1,a+n);
    init();
    for(int i=1;i<=n;++i){
        if(a[i] == a[i-1]) ans[i] = ans[i-1] + 1;
        else if(!vis[a[i]]) ans[i] = f[1];
        else{
            //2,3,5,7
            int x=a[i];
            while(x%2==0){
                x/=2;
                if(!vis[x]) ans[i] = 1 + f[2];
                else if (x < MAXN) ans[i] = max(ans[i],1 + f[x]);
            }
            x=a[i];
            while(x%3==0){
                x/=3;
                if(!vis[x]) ans[i] = 1 + f[3];
                else if (x < MAXN) ans[i] = max(ans[i],1 + f[x]);
            }
            x=a[i];
            while(x%5==0){
                x/=5;
                if(!vis[x]) ans[i] = 1 + f[5];
                else if (x < MAXN) ans[i] = max(ans[i],1 + f[x]);
            }
            x=a[i];
            while(x%7==0){
                x/=7;
                if(!vis[x]) ans[i] = 1 + f[7];
                else if (x < MAXN) ans[i] = max(ans[i],1 + f[x]);
            }
            
            for(int j=5;pri[j]*pri[j]<a[i];++j){
                if(a[i] % pri[j] == 0) ans[i] = max(ans[i],f[a[i]/pri[j]]);
            }
        }
    }
}