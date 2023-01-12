#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<long long> v(n), a1(n), a2(n);
        for (auto &i : v)
            cin >> i;
        ll s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                a1[i] = v[i];
                a2[i] = 1;
                s2 += v[i] - 1;
            }
            else
            {
                a1[i] = 1;
                a2[i] = v[i];
                s1 += v[i] - 1;
            }
        }
        if (s1 <= s2)
        {
            for (auto &i : a1)
                cout << i << " ";
            cout << endl;
        }
        else
        {
            for (auto &i : a2)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
