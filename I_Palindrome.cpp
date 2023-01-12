#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    char s[1003];
    gets(s);
    int l = strlen(s);
    int flag = 1;
    for (int i = 0, j = l - 1; i <= j; i++, j--)
    {
        if (s[i] != s[j])
        {
            flag = 0;
            break;
        }
    }
    if (flag)
        puts("YES");
    else
        puts("NO");
    return 0;
}