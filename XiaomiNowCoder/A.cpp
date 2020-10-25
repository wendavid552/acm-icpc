#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxn = 2e5+10;
const int MAX = 1e7;
int n;
int a[maxn];
int f[maxn];
int lasn[maxn];
int main(){
    scanf("%d",&n);
    fo(i,1,n) scanf("%d",a+i);
    //1.The repetence Nums
    sort(a+1,a+n+1);
    int MaxAns = 0;
    fo(i,1,n){
        if(a[i] == a[i-1]){
            f[i] = f[i-1] + 1;
            lasn[i] = lasn[i-1];
            if(MaxAns < f[i]) MaxAns = f[i];
            continue;
        }
        else{
            lasn[i] = i-1;
        }
        f[i] = 1;
        int lasp = i;
        for(int j=2;j<=a[i];++j){
            if(a[i] % j == 0){
                int k = upper_bound(a+1,a+lasp,a[i] / j) - a;
                // printf("k=%d\n",k);
                if (k!=lasp || a[k-1]==a[i]/j){
                    lasp = k;
                    f[i] = max(f[i],f[k-1]+1);
                    
                }
                j = a[i] / (a[lasn[i]]);
            }
        }
        // printf("%d %d\n",a[i],f[i]);
        if(MaxAns < f[i]){
            MaxAns = f[i];
        }
    }
//    fo(i,1,n) printf("%d ",f[i]); printf("\n");
    printf("%d\n",MaxAns);
    return 0;
}