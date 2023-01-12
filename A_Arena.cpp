#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        // ll n;
        // cin >> n;
        // vector<int> v(n);
        // for (auto &i : v)
        //     cin >> i;
        // ll x = *min_element(v.begin(), v.end());
        // ll cnt = 0;
        // for (auto &i : v)
        // {
        //     if (i != x)
        //         cnt++;
        // }
        // cout << cnt << endl;
        int x = min({4, 5, 7, 2, 1, 9});
        cout << x << endl;
    }
    return 0;
}