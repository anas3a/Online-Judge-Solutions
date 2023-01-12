#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    char x[30], y[30];
    gets(x), gets(y);
    printf("%d %d\n", strlen(x), strlen(y));
    printf("%s%s\n", x, y);
    char c = x[0];
    x[0] = y[0];
    y[0] = c;
    printf("%s %s\n", x, y);
    return 0;
}