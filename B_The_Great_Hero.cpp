#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        vector<pair <long, long> > v(n);
        for (auto &i : v)
            cin >> i.first;
        for (auto &i : v)
            cin >> i.second;
        bool f = true;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            ll x = v[i].second / a;
            if (v[i].second % a)
                x++;
            b -= v[i].first * x;
            if (b <= 0)
            {
                if (i == n - 1 && x == 1)
                    continue;
                if (i == n - 1 && x > 1 && abs(b) < v[i].first)
                    continue;
                f = false;
                break;
            }
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}