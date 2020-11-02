# include <bits/stdc++.h>
using namespace std;
const int maxs = 1e7+10;
int n;
int cnt[maxs];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        int a; scanf("%d",&a);
        cnt[a]++;
    }
    for(int i=1;i<maxs;++i)
        if(cnt[i]){
            for(int j=i+i;j<maxs;j+=i){
                cnt[j] = max(cnt[j],cnt[i]);
            }
        }

    return 0;
}
