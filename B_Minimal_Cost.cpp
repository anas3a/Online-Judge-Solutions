#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, u, z;
        cin >> n >> u >> z;
        vector<ll> v(n);
        bool f1 = true, f2 = true;
        for (auto &i : v)
            cin >> i;
        for (int i = 1; i < n; i++)
        {
            if (v[i] != v[i - 1])
                f1 = false;
            if (abs(v[i] - v[i - 1]) != 1)
                f2 = false;
        }
        if (f1)
        {
            if (n == 2)
                cout << u + z << endl;
            else
                cout << min(u + z, z + z) << endl;
        }
        else if (f2)
            cout << min(u, z) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
