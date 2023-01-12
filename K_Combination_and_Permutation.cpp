#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl
ll f(ll n)
{
    if (n <= 1)
        return 1;
    return n * f(n - 1);
}
int main()
{
    ll a, b;
    cin >> a >> b;
    cout << f(a) / f(b) / f(a - b) << " " << f(a) / f(a - b) << endl;
    return 0;
}
