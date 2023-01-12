#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ll n;
    cin >> n;
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += log10(i);
    }
    ans = max(ans, 1.0);
    cout << "Number of digits of " << n << "! is " << ceil(ans) << endl;
    return 0;
}
