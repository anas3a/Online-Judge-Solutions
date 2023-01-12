#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if (k <= n)
            cout << 1 << endl;
        else
        {
            ll z = k / n;
            if (k % n)
                z++;
            cout << z << endl;
        }
    }
}