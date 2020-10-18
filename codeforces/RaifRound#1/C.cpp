#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxl = 2e5+10;
char s[maxl];
stack<int> sta;
void solve(){
    scanf("%s",s+1);
    int l=strlen(s+1);
    int cnt = 0;
    fo(i,1,l){
        if(s[i] == 'A'){
            sta.push(1);
        }
        else if(s[i] == 'B'){
            if(!sta.empty()){
                sta.pop();
                cnt += 2;
            }
            else sta.push(2);
        }
    }
    while(!sta.empty()) sta.pop();
    printf("%d\n",l-cnt);
}
int main(){
    int T; scanf("%d",&T);
    while(T--)solve();
    return 0;
}
