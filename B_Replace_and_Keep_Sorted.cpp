#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll n, q, k;
    cin >> n >> q >> k;
    vector<ll> v(n), vx(n, 0);
    for (auto &i : v)
        cin >> i;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            vx[i] = v[i] - 1;
            if (i == n - 1)
                vx[i] += k - v[i];
            else
                vx[i] += v[i + 1] - v[i] - 1;
        }
        else if (i == n - 1)
            vx[i] += k - v[i];
        else
            vx[i] = (v[i] - v[i - 1] - 1) + (v[i + 1] - v[i] - 1);
    }
    for (int i = 1; i < n; i++)
    {
        vx[i] += vx[i - 1];
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        l -= 2, r--;
        ll ans = 0;
        if (l < 0)
        {
            ans = vx[r];
            if (r != n - 1)
                ans += k - vx[r] - 1 - (vx[r + 1] - vx[r] - 1);
        }
        else
        {
            ans = vx[r] - vx[l];
            if (l != 0)
                ans += v[l] - 1 - (v[l] - v[l - 1] - 1);
            if (r != n - 1)
                ans += k - vx[r] - 1 - (vx[r + 1] - vx[r] - 1);
        }
        cout << ans << endl;
    }
    return 0;
}