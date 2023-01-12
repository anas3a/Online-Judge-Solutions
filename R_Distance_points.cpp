#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << fixed << setprecision(9) << sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    return 0;
}
