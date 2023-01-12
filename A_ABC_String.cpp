#include <bits/stdc++.h>

using namespace std;

using ll = long long;



#define sz(v) ((int)(v).size())


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll a = 0, b = 0, c = 0;
        for (int i = 0; i < sz(s); i++)
        {
            if (s[i] == 'A')
                a++;
            else if (s[i] == 'B')
                b++;
            else
                c++;
        }
        ll z = max({a, b, c});
        if (z != (a + b + c) - z)
        {
            cout << "NO" << endl;
            continue;
        }
        char m;
        if (a == z)
            m = 'A';
        else if (b == z)
            m = 'B';
        else
            m = 'C';
        char n, o;
        if (s[0] == m)
            n = '(', o = ')';
        else
            n = ')', o = '(';
        for (int i = 0; i < sz(s); i++)
        {

            if (s[i] == m)
                s[i] = n;
            else
                s[i] = o;
        }
        bool f = true;
        ll p = 0;
        for (int i = 0; i < sz(s); i++)
        {
            if (s[i] == '(')
                p++;
            else
            {
                p--;
                if (p < 0)
                {
                    f = false;
                    break;
                }
            }
        }
        if (!f || p != 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
