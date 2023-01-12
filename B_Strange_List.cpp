#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, sum = 0;
        cin >> n >> x;
        vector<int> v(n);
        for (auto &i : v)
        {
            cin >> i;
            sum += i;
        }
        ll b = 1e9;
        for (int i = 0; i < n; i++)
        {
            ll z = v[i];
            ll cnt = 0;
            while (z % x == 0)
            {
                if (cnt >= b)
                break;
                z /= x;
                ll m = x;
                for (int j = 0; j < cnt; j++)
                    m *= m;
                sum += m * z;
                cnt++;
            }
            b = min(b, cnt);
        }
        cout << sum << endl;
    }
}
