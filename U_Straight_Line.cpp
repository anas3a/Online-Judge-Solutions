#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double z = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
    if (z)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
