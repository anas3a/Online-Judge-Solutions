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
        ll a, b, c;
        cin >> a >> b >> c;

        ll z = abs(a - b);
        if (c - z <= 0 && z + c > 0)
            cout << -1 << endl;
        else if (z + c == max(a, b) && c - z == min(a, b))
            cout << -1 << endl;
        else if (c - z > 0)
            cout << c - z << endl;
        else
            cout << z + c << endl;
    }
    return 0;
}
