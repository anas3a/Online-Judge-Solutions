#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end());
        bool f = false;
        for (int i = 0; i < n; i++)
        {
            ll x = abs(v[0].first - v[i].first) + abs(v[0].second - v[i].second);
            ll y = abs(v[i].first - v[n - 1].first) + abs(v[i].second - v[n - 1].second);
            if (x <= k && y <= k)
                f = true;
        }
        if (f)
            cout << 1 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}