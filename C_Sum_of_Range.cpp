#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ll a, b;
    cin >> a >> b;
    if (b < a)
        swap(a, b);
    ll s1 = ((b - a + 1) * (b + a)) / 2;
    ll x1 = a - 1;
    x1 = ceil(x1 / 2.0) * ceil(x1 / 2.0);
    ll s3 = (ceil(b / 2.0) * ceil(b / 2.0)) - x1;
    ll s2 = s1 - s3;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    return 0;
}
