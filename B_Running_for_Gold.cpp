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
        vector<vector<ll>> v(n, vector<ll>(5));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
                cin >> v[i][j];
        }
        ll w = 0;
        for (int i = 1; i < n; i++)
        {
            int cnt1 = 0;
            for (int j = 0; j < 5; j++)
            {
                if (v[w][j] < v[i][j])
                    cnt1++;
            }
            if (cnt1 < 3)
                w = i;
        }
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            int cnt1 = 0;
            if (i == w)
                continue;
            for (int j = 0; j < 5; j++)
            {
                if (v[w][j] < v[i][j])
                    cnt1++;
            }
            if (cnt1 < 3)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << w + 1 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
