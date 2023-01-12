#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        char s[101];
        gets(s);
        if (strlen(s) <= 10)
            puts(s);
        else
        {
            int n = strlen(s);
            printf("%c%d%c\n", s[0], n - 2, s[n - 1]);
        }
    }
    return 0;
}