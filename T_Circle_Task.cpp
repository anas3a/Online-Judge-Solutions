#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ll x, y, r, n;
    cin >> x >> y >> r >> n;
    while (n--)
    {
        ll x1, y1;
        cin >> x1 >> y1;
        if (sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)) <= r)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
