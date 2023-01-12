#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    // ll n;
    // cin >> n;
    // ll a = n;
    // ll b = 1;
    // for (int i = 0; i < 100; i++)
    // {
    //     cout << i + 1 << " = " << a << " " << b << endl;
    //     a--;
    //     b++;
    //     if (a == 0)
    //         a = n;
    //     if (b > n)
    //         b = 1;
    //     if (a == b)
    //         b++;
    //     if (b > n)
    //         b = 1;
    // }
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if (n % 2 == 0)
        {
            ll x = (k % n);
            if (x == 0)
                x = n;
            cout << x << endl;
        }   
        else
        {
            ll x = (k % n);
            if (x == 0)
                x = n;
            ll y = n / 2;
            ll z = (k - 1) / y;
            x += z;
            x %= n;
            if (x == 0)
                x = n;
            cout << x << endl;
        }
    }
    return 0;
}