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
        ll k;
        cin >> k;
        ll z = ceil(sqrt(k));
        ll y = z * z - k;
        ll a, b;
        if (y < z)
        {
            b = y + 1;
            a = z;
            if (a & 1)
                swap(a, b);
        }
        else
        {
            a = 2 * z - y - 1;
            b = z;
            if (b & 1)
                swap(a, b);
        }
        // if (z & 1)
        //     swap(a, b);
        cout << a << " " << b << endl;
    }
    return 0;
}
