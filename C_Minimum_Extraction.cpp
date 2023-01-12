#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll v(n);
        ll mn = 0;
        for (auto &i : v)
            cin >> i, mn = min(i, mn);
        if (n == 1)
        {
            cout << v[0] << endl;
            continue;
        }
        if (mn < 0)
        {
            for (auto &i : v)
                i -= mn;
        }
        ll mx = *max_element(v.begin(), v.end());
        sort(v.begin(), v.end());
        ll x = 0;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (v[i] * 2 > mx)
            {
                // if (v[0] == v[i])
                //     cout << v[i] << endl;
                // else
                    cout << v[i] - x << endl;
                flag = true;
                break;
            }
            x = v[i];
        }
        if (!flag)
            cout << v[n - 1] << endl;
    }
    return 0;
}