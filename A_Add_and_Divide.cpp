#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll cnt = 1e10;
        for (ll i = b; i <= b + 100; i++)
        {
            ll cx = i - b, c = i, d = a;
            if (c == 1)
            {
                cx++;
                c++;
            }
            while (d != 0)
            {
                cx++;
                d /= c;
            }
            cnt = min(cnt, cx);
        }
        cout << cnt << endl;
    }
    return 0;
}