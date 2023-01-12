#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    double a1, b1, a2, b2;
    if (x2 - x1 == 0)
        a1 = 1, b1 = 0;
    else
    {
        a1 = -(double)(y2 - y1) / (x2 - x1);
        b1 = 1;
    }
    if (x4 - x3 == 0)
        a2 = 1, b2 = 0;
    else
    {
        a2 = -(double)(y4 - y3) / (x4 - x3);
        b2 = 1;
    }
    if (abs(a2 - a1) <= 1e-9 && abs(b2 - b1) <= 1e-9)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
