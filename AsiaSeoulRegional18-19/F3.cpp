#include <bits/stdc++.h>
using namespace std;

#define N 1000100
char s[N];
int id[N], len;

bool ok()
{
    len = strlen(s + 1);
    for (int i = 1; i <= len; ++i)
    {
        if (isalpha(s[i]))
            id[i] = 0;
        else if (s[i] == '+' ||
                 s[i] == '-' ||
                 s[i] == '*' ||
                 s[i] == '/' ||
                 s[i] == '%')
                 id[i] = 1;
        else if (s[i] == '(')
            id[i] = 2;
        else
            id[i] = 3;
    }
    if (id[1] == 3 || id[len] == 2) return false;
    if (id[1] == 1 || id[len] == 1) return false;
    if (len == 1 && id[1] == 0)
        return true;
    for (int i = 2, x, y; i <= len; ++i)
    {
        x = id[i - 1], y = id[i];
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
    for (int i = 1; i <= len; ++i)
    {
        if (id[i] == 2)
            ++cnt;
        else if (id[i] == 3)
        {
            if (cnt == 0)
                return false;
            --cnt;
        }
    }
    return cnt == 0;
}

bool work()
{
    if (len == 1) return true;
    int cnt = 0, sym = 0;
    for (int i = 1; i <= len; ++i)
        sym += (id[i] == 1);
    stack <int> sta;
    for (int i = 1; i <= len; ++i)
    {
        if (id[i] == 0)
            continue;
        else if (id[i] <= 2)
            sta.push(id[i]);
        else if (id[i] == 3)
        {
            int flag = 0;
            while (!sta.empty())
            {
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

int main()
{
    gets(s + 1);
    {
        len = strlen(s + 1);
        //if (len == 0) continue;
        int now = 0;
        for (int i = 1; i <= len; ++i)
            if (s[i] != ' ')
                s[++now] = s[i];
        s[++now] = 0;
//        cout << s + 1 << endl;
        if (!ok()) puts("error");
        else
            puts(work() ? "proper" : "improper");
    }
    return 0;
}
