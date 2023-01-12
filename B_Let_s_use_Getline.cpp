#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n = 1e6 + 3;
    char s[n];
    scanf("%[^\n]s", s);
    for (int i = 0; s[i] != '\\'; i++)
        printf("%c", s[i]);
    printf("\n");
    return 0;
}