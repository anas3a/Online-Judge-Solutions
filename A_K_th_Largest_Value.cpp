#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, q, c0 = 0, c1 = 0;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
        if (i)
            c1++;
        else
            c0++;
    }
    while (q--)
    {
        ll t, x;
        cin >> t >> x;
        if (t == 1)
        {
            x--;
            if (v[x])
            {
                v[x] = 0;
                c0++;
                c1--;
            }
            else
            {
                v[x] = 1;
                c1++;
                c0--;
            }
        }
        else
        {
            if (x <= c1)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}
