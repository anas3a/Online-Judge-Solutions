#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ll t;
    cin >> t;
    ll x = 1e12;
    ll i = 1;
    vector<ll> v;
    while (true)
    {
        if (i * i * i >= x)
            break;
        v.push_back(i * i * i);
        i++;
    }
    set<ll> s;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i; j < v.size(); j++)
            s.insert(v[i] + v[j]);
    }
    while (t--)
    {
        ll n;
        cin >> n;
        if (s.count(n))
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}