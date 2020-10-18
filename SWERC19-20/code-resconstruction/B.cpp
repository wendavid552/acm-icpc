# include <iostream>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <string>
# define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxn = 2e5+10;
int n;
string t[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    fo(i,1,n){
        cin >> t[i];
    }
    sort(t+1,t+n+1);
    fo(i,1,n){
        fo(j,i,n){
            if(t[j]!=t[j+1] && (j-i+1)*2 > n){
                cout << t[j] << '\n';
                return 0;
            }
            else if ((j-i+1)*2 <= n){
                i = j;
            }
        }
    }
    cout << "NONE" << '\n';
    return 0;
}
