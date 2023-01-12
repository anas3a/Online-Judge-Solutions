#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    char t[10] = "hello";
    char s[10004];
    int flag = 0;
    gets(s);
    for (int i = 0, j = 0; s[i] != '\0'; i++)
    {
        if (s[i] == t[j])
            j++;
        if (j == 5)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        puts("YES");
    else
        puts("NO");
    return 0;
}