#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll q;
    cin >> q;
    while (q--)
    {
        string s, t;
        cin >> s >> t;
        if (s.size() < t.size())
            swap(s, t);
        bool f = true, fx = true;
        string m;
        for (int i = 0; i < t.size(); i++)
        {
            string x;
            for (int j = 0; j <= i; j++)
                x += t[j];
            if (t.size() % x.size() == 0)
            {
                fx = true;
                for (int j = 0, k = 0; j < t.size(); j++, k++)
                {
                    if (k == x.size())
                        k = 0;
                    if (t[j] != x[k])
                    {
                        fx = false;
                        break;
                    }
                }
                if (fx)
                {
                    m = x;
                    break;
                }
            }
        }
        if (fx)
        {
            if (s.size() % m.size() != 0)
            {
                f = false;
            }
            for (int i = 0, j = 0; i < s.size(); i++, j++)
            {
                if (j == m.size())
                    j = 0;
                if (s[i] != m[j])
                {
                    f = false;
                    break;
                }
            }
        }
        if (f && m.size() != 0)
        {
            ll a = s.size() / m.size();
            ll b = t.size() / m.size();
            ll z = (a * b) / __gcd(a, b);
            for (int i = 0; i < z; i++)
                cout << m;
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
}
