#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
int main(){
    int T; scanf("%d",&T);
    fo(i,1,T){
        int x; scanf("%d",&x);
        int t=x%10;
        int v = 1;
        if(x == t*11)v=3;
        if(x == t*111)v=6;
        if(x == t*1111) v=10;
        printf("%d\n",(t-1)*10+v);
    }
    return 0;
}
