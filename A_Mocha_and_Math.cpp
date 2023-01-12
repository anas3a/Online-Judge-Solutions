#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
        vector<ll> v(n);
        for (auto &i : v)
            cin >> i;
        ll a = v[0], b = v[0];
        for (int i = 1; i < n; i++)
        {
            a = (a & v[i]);
            b = min(b, v[i]);
        }
        if (a == 0)
            cout << a << endl;
        else
            cout << b << endl;
    }
    return 0;
}
