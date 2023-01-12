#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<int> vx(n);
        vector<int> v(3, 0);
        for (auto &i : vx)
        {
            cin >> i;
            v[i % 3]++;
        }
        ll cnt = 0;
        ll x = n / 3;
        if (v[0] < x)
        {
            if(v[2] > x)
            {
                ll z = min(x - v[0], v[2] - x);
                v[0] += z;
                v[2] -= z;
                cnt += z;
            }
            if (v[1] > x)
            {
                ll z = min(x - v[0], v[1] - x);
                v[0] += z;
                v[1] -= z;
                cnt += 2 * z;
            }
        }
        if (v[1] < x)
        {
            if(v[0] > x)
            {
                ll z = min(x - v[1], v[0] - x);
                v[1] += z;
                v[0] -= z;
                cnt += z;
            }
            if (v[2] > x)
            {
                ll z = min(x - v[1], v[2] - x);
                v[1] += z;
                v[2] -= z;
                cnt += 2 * z;
            }
        }
        if (v[2] < x)
        {
            if(v[1] > x)
            {
                ll z = min(x - v[2], v[1] - x);
                v[2] += z;
                v[1] -= z;
                cnt += z;
            }
            if (v[0] > x)
            {
                ll z = min(x - v[2], v[0] - x);
                v[2] += z;
                v[0] -= z;
                cnt += 2 * z;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}