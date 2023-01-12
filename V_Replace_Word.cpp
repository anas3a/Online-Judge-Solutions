#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    char s[1003];
    gets(s);
    int l = strlen(s);
    for (int i = 0; i < l; i++)
    {
        if (i < l - 4 && s[i] == 'E' && s[i + 1] == 'G' && s[i + 2] == 'Y' && s[i + 3] == 'P' && s[i + 4] == 'T')
        {
            putchar(' ');
            i += 4;
        }
        else
            putchar(s[i]);
    }
    putchar('\n');
    return 0;
}