#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        int n = 1e5 + 3;
        char s[n];
        gets(s);
        int flag = 0;
        int l = strlen(s);
        for (int i = 0; i < l - 2; i++)
        {
            if (s[i] == '0' && s[i + 1] == '1' && s[i + 2] == '0')
            {
                flag = 1;
                break;
            }
            if (s[i] == '1' && s[i + 1] == '0' && s[i + 2] == '1')
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            puts("Good");
        else
            puts("Bad");
    }
    return 0;
}