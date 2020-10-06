#include <iostream>
#include <algorithm>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
void
solve()
{
    long long a,b,c,d;
    cin >> a >> b >> c;
    cout << (d=max(a,max(b,c))+1) << '\n';
}
int
main()
{
    ios::sync_with_stdio(false);
    int t; cin >> t;
    fo(i,1,t) solve();
    return 0;
}
