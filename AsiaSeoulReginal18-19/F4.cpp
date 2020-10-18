#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxl = 1e5+10;
char s[maxl];
int l;
int d[maxl];
bool judge(){
    l=strlen(s+1);
    fo(i,1,l){
        if (isalpha(s[i]))
            d[i] = 0;
        else if (s[i] == '+' ||
                 s[i] == '-' ||
                 s[i] == '*' ||
                 s[i] == '/' ||
                 s[i] == '%')
                 d[i] = 1;
        else if (s[i] == '(')
            d[i] = 2;
        else
            d[i] = 3;
    }
    if (d[1] == 3 || d[l] == 2) return false;
    if (d[1] == 1 || d[l] == 1) return false;
    if (l == 1 && d[1] == 0)
        return true;
    for (int i = 2, x, y; i <= l; ++i)
    {
        x = d[i - 1], y = d[i];
        if (x == 0 && y == 0)
            return false;
        if (x == 1 && y == 1)
            return false;
        if (x == 1 && y == 3)
            return false;
        if (x == 2 && y == 1)
            return false;
        if (x == 2 && y == 3)
            return false;
        if (x == 3 && y == 2)
            return false;
        if (x == 3 && y == 0)
            return false;
        if (x == 0 && y == 2)
            return false;
    }
    int cnt = 0;
    for (int i = 1; i <= l; ++i){
        if (d[i] == 2)
            ++cnt;
        else if (d[i] == 3){
            if (cnt == 0)
                return false;
            --cnt;
        }
    }
    return cnt == 0;
}
stack<int>sta;
bool solve()
{
    if (l == 1) return true;
    int cnt = 0, sym = 0;
    fo(i,1,l) sym += (d[i] == 1);
    fo(i,1,l){
        if (d[i] == 0)
            continue;
        else if (d[i] <= 2)
            sta.push(d[i]);
        else if (d[i] == 3){
            int flag = 0;
            while (!sta.empty()){
                int top = sta.top(); sta.pop();
                if (top == 2)
                    break;
                if (top == 1)
                    ++flag;
            }
            if (flag == 1) ++cnt;
            else
                return false;
        }
    }
    return cnt == sym - 1;
}
int main(){
    gets(s + 1);
    l = strlen(s + 1);
    int np = 0;
    fo(i,1,l)
        if (s[i] != ' ')
            s[++np] = s[i];
    s[++np] = 0;
    if (!judge()) puts("error");
    else
        puts(solve() ? "proper" : "improper");
    return 0;

}
/*#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxl = 1e5+10;
char s[maxl];
int l;
int d[maxl];
bool judge(){
    l=strlen(s+1);
    fo(i,1,l){
        if (isalpha(s[i]))
            d[i] = 0;
        else if (s[i] == '+' ||
                 s[i] == '-' ||
                 s[i] == '*' ||
                 s[i] == '/' ||
                 s[i] == '%')
                 d[i] = 1;
        else if (s[i] == '(')
            d[i] = 2;
        else if (s[i] == ')')
            d[i] = 3;
    }
    if (d[1] == 3 || d[l] == 2) return false;
    if (d[1] == 1 || d[l] == 1) return false;
    if (l == 1 && d[1] == 0)
        return true;
    for (int i = 2, x, y; i <= l; ++i)
    {
        x = d[i - 1], y = d[i];
        if (x == 0 && y == 0)
            return false;
        if (x == 1 && y == 1)
            return false;
        if (x == 1 && y == 3)
            return false;
        if (x == 2 && y == 1)
            return false;
        if (x == 2 && y == 3)
            return false;
        if (x == 3 && y == 2)
            return false;
        if (x == 3 && y == 0)
            return false;
        if (x == 0 && y == 2)
            return false;
    }
    int cnt = 0;
    for (int i = 1; i <= l; ++i){
        if (d[i] == 2)
            ++cnt;
        else if (d[i] == 3){
            if (cnt == 0)
                return false;
            --cnt;
        }
    }
    return cnt == 0;
}
stack<int>sta;
bool solve()
{
    if (l == 1) return true;
    int cnt = 0, sym = 0;
    fo(i,1,l) sym += (d[i] == 1);
    fo(i,1,l){
        if (d[i] == 0)
            continue;
        else if (d[i] <= 2)
            sta.push(d[i]);
        else if (d[i] == 3){
            int flag = 0;
            while (!sta.empty()){
                int top = sta.top(); sta.pop();
                if (top == 2)
                    break;
                if (top == 1)
                    ++flag;
            }
            if (flag == 1) ++cnt;
            else
                return false;
        }
    }
    return cnt == sym - 1;
}
int main(){
    gets(s + 1);
    l = strlen(s + 1);
    int np = 0;
    fo(i,1,l)
        if (s[i] != ' ')
            s[++np] = s[i];
    s[++np] = 0;
    if (!judge()) puts("error");
    else
        puts(solve() ? "proper" : "improper");
    return 0;

}*/
