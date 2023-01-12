#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n;
    scanf("%d\n", &n);
    char s[100005];
    gets(s);
    int ans = 1;
    for (int i = 1; s[i] != '\0'; i++)
    {
        if (s[i - 1] != s[i])
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}