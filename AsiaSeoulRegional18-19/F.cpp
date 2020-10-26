# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <queue>
# include <algorithm>
# define LL long long
# define pb push_back
# define mp make_pair
# define fi first
# define se second
# define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxl = 1010;
char s[maxl];
struct suf{
	char c;	//a-z or $ if ()
	char k;
	int op;	//1 2 3 4
} sta[maxl]; int p = 0;
void solve()
{
	int l=strlen(s+1);
	for(i,1,l){
		if(s[i]<='z' && s[i] >='a'){
			if(sta[p].c==0){
				sta[p].c = s[i];
			}
			else if(sta[p].k==0 && sta[p].op){
				sta[p].l = s[i];
			}
			else if(sta[p].op == 0){
				printf("error\n");
				return 0;
			}
		}
		else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
			if(sta[p].op == 0 && sta[p].c && sta[p].k==0){
				switch(s[i]){
					case '+': s[i]=1; break;
					case '-': s[i]=2; break;
					case '*': s[i]=3; break;
					case '/': s[i]=4; break;
				}
			}
			else if(sta[p].op != 0){
				printf("error\n");
			}
			else if(sta[p].c == 0 || sta[p].k != 0){
				printf("error\n");
			}
			else{
				printf("imporper\n");
				return 0;
			}
		}
		else if(s[i] == '('){
			++p;
			
		}
		else if(s[i] == ')'){
			if(p == 0){
				printf("error\n");
				return 0;
			}
			if(sta[p].c && sta[p].k && sta[p].op){
				--p;
				if(sta[p].c == 0) sta[p].c = '$';
				else if(sta[p].k == 0) sta[p].k = '$';
			}
		}
	}
}
int main()
{
	scanf("%s",s+1);
	solve();
	return 0;
}