#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n = 1e6 + 6;
    char s[n];
    gets(s);
    int cnt = 0, found = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isalpha(s[i]))
            found = 1;
        if (isalpha(s[i]) == 0 && found)
        {
            cnt++;
            found = 0;
        }
    }
    if (found)
        cnt++;
    printf("%d\n", cnt);
    return 0;
}