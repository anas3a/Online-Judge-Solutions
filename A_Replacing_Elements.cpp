#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, d;
        cin >> n >> d;
        vector<ll> v(n);
        for (auto &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        if (v[0] + v[1] <= d || v[n - 1] <= d)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
