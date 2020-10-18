# include<bits/stdc++.h>
# define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
map<string,int> M;
int n;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    fo(i,1,n){
        cin >> s;
        M[s]++;
    }
    for(map<string,int>::iterator it=M.begin();it!=M.end();++it){
        if(it->second * 2 > n){
            cout << it->first << '\n';
            return 0;
        }
    }
    cout << "NONE" << endl;
    return 0;
}
