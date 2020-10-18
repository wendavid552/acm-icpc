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
int l;
int solve(int x){
	int j = x;
	char l=0,r=0; int op = 0;
	for(;j<=l;++j){
		if(s[j] == '('){
			int t=solve(j+1);
			if(t == -1) return -1;
			if(t == -2) return -2;
			j = t;
		}
		else if(s[j] == '+' || s[j] == '-' || s[j] == '*' || s[j] == '/'){
			switch(s[i]){
				case '+': op=1; break;
				case '-': op=2; break;
				case '*': op=3; break;
				case '/': op=4; break;
			}
		}
		else if(s[j] <='z' || s[j] >= 'a'){
			
		}
	}
}
int main()
{
	scanf("%s",s+1);
	l=strlen(s+1);
	int t=solve(1);	//l = ok, -1 = error, -2 = improper
	if(t == -1) printf("error\n");
	else if (t == -2) printf("improper\n");
	else printf("proper\n");
	return 0;
}