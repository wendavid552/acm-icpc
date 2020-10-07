#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
LL A,B;
int
main()
{
    LL N,A,B;
    cin >> N >> A >> B;
    if(A>B)swap(A,B);
    if((A&1) == (B&1)){
        cout << ((B-A)>>1) << endl;
    }
    else{
        cout << min(A-1,N-B)+1+((B-A-1)>>1) <<endl;
    }
    return 0;
}
