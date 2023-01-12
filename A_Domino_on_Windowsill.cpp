#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k1, k2, w, b;
        cin >> n >> k1 >> k2 >> w >> b;
        bool f = true;
        // ll z = min(k1, k2);
        // w -= z;
        // k1 -= z;
        // k2 -= z;
        // w -= (k1 + k2) / 2;
        // if (w > 0)
        //     f = false;
        // ll k3 = n - k1, k4 = n - k2;
        // z = min(k3, k4);
        // b -= z;
        // k3 -= z;
        // k4 -= z;
        // b -= (k3 + k4) / 2;
        // if (b > 0)
        //     f = false;
        ll x = k1 + k2;
        if (x / 2 < w)
            f = false;
        ll y = (n - k1 + n - k2);
        if (y / 2 < b)
            f = false;
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
