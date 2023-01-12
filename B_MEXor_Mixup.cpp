#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll ar[400000];
int main()
{
    ll t;
    cin >> t;
    ll a, b;
    ll z = 400000;
    ar[0] = 0;
    for (ll i = 1; i < z - 2; i++)
    {
        ar[i] = (ar[i - 1] ^ i);
    }
    while (t--)
    {
        cin >> a >> b;
        ll ans = a;
        if (a == b)
            ans++;
        if (ar[a - 1] != b)
            ans++;
        cout << ans << endl;
    }
    return 0;
}
