#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll x = a + b + c;
        ll y = x / 9;
        if (x % 9 == 0 && a >= y && b >= y && c >= y)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
