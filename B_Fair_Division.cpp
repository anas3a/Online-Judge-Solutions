#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a == 1)
                c1++;
            else
                c2++;
        }
        bool f = true;
        if (c2 & 1)
            c1 -= 2;
        if (c1 < 0)
            f = false;
        if (c1 & 1)
            f = false;
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
