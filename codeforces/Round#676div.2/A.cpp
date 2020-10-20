#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
/*
6 = 2 + 4
12 = 4 + 8

-> 2 + 8 ???
*/
void solve(){
    int a,b; scanf("%d%d",&a,&b);
    long long k = 0;
    int j=0;
    while (a > 0 || b > 0){
        if((a & 1) != (b & 1)) k += (1ll << j);
        ++j; a>>=1; b>>=1;
    }
    cout << k << endl;
}
int main(){
    int T; scanf("%d",&T);
    while(T--) solve();
    return 0;
}
