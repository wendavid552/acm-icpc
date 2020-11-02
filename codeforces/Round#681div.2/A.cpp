# include<bits/stdc++.h>
using namespace std;
int main(){
    int T; scanf("%d",&T);
    int n;
    while(T--){
        scanf("%d",&n);
        for(int i=n*2;i<n*4;i+=2) printf("%d ",i);
        printf("\n");
    }
    return 0;
}
