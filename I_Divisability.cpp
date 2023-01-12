#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ll a, b, x;
    cin >> a >> b >> x;
    if (a < b)
        swap(a, b);
    ll m = a / x;
    ll n = (b - 1) / x;
    m = x * ((m * (m + 1)) / 2);
    n = x * ((n * (n + 1)) / 2);
    cout << m - n << endl;
    return 0;
}
