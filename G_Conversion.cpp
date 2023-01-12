#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n = 1e5 + 3;
    char s[n];
    gets(s);
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ',')
            s[i] = ' ';
        else
            s[i] = (isupper(s[i]) ? tolower(s[i]) : toupper(s[i]));
    }
    puts(s);
    return 0;
}