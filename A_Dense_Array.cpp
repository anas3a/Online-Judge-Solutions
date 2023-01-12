#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n; 
        vector<int> v(n);
        for (auto &&i : v)
        {
            cin >> i;
        }
        ll cnt = 0;
        for (int i = 1; i < n; i++)
        {
            if (v[i] > v[i - 1] * 2)
            {
                ll x = v[i - 1];
                while (x * 2 < v[i])
                {
                    cnt++;
                    x *= 2;
                }
            }
            if (v[i] * 2 < v[i - 1])
            {
                ll x = v[i];
                while (x * 2 < v[i - 1])
                {
                    cnt++;
                    x *= 2;
                }
            }
        }
        cout << cnt << endl;
        
        
    }
    return 0;
}