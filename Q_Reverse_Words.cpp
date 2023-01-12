#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n = 1e6 + 6;
    char s[n], t[n];
    gets(s);
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            for (int j = i - 1; j >= 0 && s[j] != ' '; j--)
                putchar(s[j]);
            putchar(' ');
        }
    }
    for (int j = strlen(s) - 1; j >= 0 && s[j] != ' '; j--)
        putchar(s[j]);
    putchar('\n');
    return 0;
}