#include<bits/stdc++.h>
using namespace std;
const int maxn = 30010;
int n;
int a[maxn];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",a+i);
    int l=a[1],r=0; //l down, r up
    for(int i=2;i<=n;++i){
        //a[i] = l + r
        if(a[i] > a[i-1]){
            r += a[i] - a[i-1];
        }
        else if(a[i] < a[i-1]){
            l -= a[i-1] - a[i];
            if(l<0){
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
    return;
}
int main(){
    int T; scanf("%d",&T);
    while(T--)solve();
    return 0;
}
