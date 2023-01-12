#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll x, n;
        cin >> x >> n;
        if (n % 4 == 0)
            cout << x << endl;
        else
        {
            ll z = n - (n % 4);
            while (z < n)
            {
                if (x & 1)
                    x += z + 1;
                else
                    x -= z + 1;
                z++;
            }
            cout << x << endl;
        }
    }
    return 0;
}