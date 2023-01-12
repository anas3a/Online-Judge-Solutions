#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (auto &i : v)
            cin >> i;
        int x1 = -1, y1, x2, y2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == '*')
                {
                    if (x1 == -1)
                        x1 = i, y1 = j;
                    else
                        x2 = i, y2 = j;
                }
            }
        }
        if (x1 == x2)
        {
            ll z = abs(y2 - y1);
            if (x1 != n - 1)
            {
                v[x1 + 1][y1] = '*';
                v[x2 + 1][y2] = '*';
            }
            else
            {
                v[x1 - 1][y1] = '*';
                v[x2 - 1][y2] = '*';
            }
        }
        else if (y1 == y2)
        {
            ll z = abs(x1 - x2);
            if (y1 != n - 1)
            {
                v[x1][y1 + 1] = '*';
                v[x2][y2 + 1] = '*';
            }
            else
            {
                v[x1][y1 - 1] = '*';
                v[x2][y2 - 1] = '*';
            }
        }
        else
        {
            v[x1][y2] = '*';
            v[x2][y1] = '*';
        }
        for (auto &i : v)
            cout << i << endl;
    }

    return 0;
}
