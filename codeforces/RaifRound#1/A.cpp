#include<bits/stdc++.h>
using namespace std;
inline int _abs(int x){return (x>0?x:-x);}
void solve(){
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if (x1 == x2 || y1 == y2){
        printf("%d\n",_abs(x1-x2)+_abs(y1-y2));
    }
    else{
        printf("%d\n",_abs(x1-x2)+_abs(y1-y2)+2);
    }
}
int main(){
    int T; scanf("%d",&T);
    for(int kase=1;kase<=T;++kase)solve();
    return 0;
}
