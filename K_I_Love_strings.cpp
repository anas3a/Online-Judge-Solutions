#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        char x[100], y[100];
        scanf("%s %s", &x, &y);
        int lx = strlen(x), ly = strlen(y);
        for (int i = 0; i < lx || i < ly; i++)
        {
            if (i < lx)
                putchar(x[i]);
            if (i < ly)
                putchar(y[i]);
        }
        putchar('\n');
    }
    return 0;
}