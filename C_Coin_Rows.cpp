#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n = 2, m;
        cin >> m;
        vector<vector<ll>> v(2, vector<ll>(m + 3));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
            }
        }
        vector<ll> p1(m + 3, 0), p2(m + 3, 0);
        for (int i = m - 1; i >= 0; i--)
            p1[i] = v[0][i] + p1[i + 1];
        for (int i = 1; i < m; i++)
            p2[i] = v[1][i - 1] + p2[i - 1];
        ll ans = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            ans = min(ans, max(p1[i + 1], p2[i]));
        }
        cout << ans << endl;
    }
    return 0;
}
