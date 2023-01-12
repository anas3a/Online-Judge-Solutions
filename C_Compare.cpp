#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    char x[30], y[30];
    gets(x), gets(y);
    if (strcmp(x, y) <= 0)
        puts(x);
    else
        puts(y);
    return 0;
}