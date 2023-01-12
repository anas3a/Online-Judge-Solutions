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
        ll n, m;
        cin >> n >> m;
        vector<ll> v(m + 1, 0);
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v[x % m]++;
        }
        ll ans = 0;
        if (v[0] != 0)
            ans++;
        for (int i = 1; i <= m / 2; i++)
        {
            ll z = m - i;
            if (v[z] == 0 || v[i] == 0)
                ans += max(v[z], v[i]);
            else if (z == i)
            {
                ans++;
            }
            else
            {
                ans++;
                ll px = min(v[z], v[i]);
                v[z] = v[z] - px;
                v[i] = v[i] - px;
                ans += v[z];
                ans += v[i];
                if (v[z] != v[i])
                    ans--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
