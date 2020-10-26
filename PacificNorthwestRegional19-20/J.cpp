# include <bits/stdc++.h>
# define LL long long
# define pb push_back
# define mp make_pair
# define fi first
# define se second
# define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxn = 1e5+10;
int n;
struct line{
	double v;
	int typ;
	int i;
	/*
	typ = 1 =>  a
	typ = 2 =>  a[
	typ = 3 =>  a]
	*/
	bool operator<(const line& t) const{
		return v < t.v;
	}
};
double a[maxn],t[maxn],s[maxn];
vector<line> L;
double f[maxn];
/*
void TEST_getas(double x){
	double ans = 0;
	fo(i,1,n){
		ans += max(0.0,t[i] - s[i]*abs(x-a[i]));
	}
	printf("NOWANS = %.6f\n",ans);
}*/
int main()
{
	scanf("%d",&n);
	fo(i,1,n){
		scanf("%lf%lf%lf",t+i,s+i,a+i);
		line L1,L2,L3;
		L1.v = a[i]; L1.typ = 1; L1.i = i;
		L2.v = a[i]-t[i]/s[i]; L2.typ = 2; L2.i = i;
		L3.v = a[i]+t[i]/s[i]; L3.typ = 3; L3.i = i;
		L.pb(L1); L.pb(L2); L.pb(L3);
	}
	
	sort(L.begin(),L.end());
	
	int m = L.size();
	
	
	/*
	Obviously,
	The left most should be a [
	The right most should be a ]
	*/
	double nows = s[L[0].i];
	double nowLs = t[L[0].i];
	double nT = t[L[0].i];
	double ans = 0.0;
	fo(i,1,m-1){
        //if one is at the left  -> s < 0 -> bigger
        //          at the right -> s > 0 -> smaller
		nowLs -= nows * (L[i].v - L[i-1].v);
		
        f[i] = nowLs;
		if(L[i].typ == 1){
			nows -= s[L[i].i] * 2;
		}
		else if(L[i].typ == 2){
			nows += s[L[i].i];
			nowLs += t[L[i].i];
			nT += t[L[i].i];
		}
		else if(L[i].typ == 3){
			nows += s[L[i].i];
			nowLs -= t[L[i].i];
			nT -= t[L[i].i];
		}
  //      TEST_getas(L[i].v);
  //      printf("Get: T=%.6f, Ls = %.6f, Ans = %.6f\n",nT,nowLs,nT-nowLs);
		ans = max(ans,nT-nowLs);
	}
	printf("%.6f\n",ans);
	return 0;
}
