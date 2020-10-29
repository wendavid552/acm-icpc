# include <bits/stdc++.h>
using namespace std;
int main(){
    int T; scanf("%d",&T);
    for(int kase=1;kase<=T;++kase){
        int l,r; scanf("%d%d",&l,&r);
        if(l > (r-l)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
