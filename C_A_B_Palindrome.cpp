#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        bool f = true;
        string s;
        cin >> s;
        ll n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] == s[n - i - 1] && s[i] != '?')
            {
                if (s[i] == '0')
                    a -= 2;
                else
                    b -= 2;
            }
            else if (s[i] != s[n - i - 1] && (s[i] == '?' || s[n - i - 1] == '?'))
            {
                if (s[i] == '?')
                {
                    if (s[n - i - 1] == '0')
                    {
                        if (a > 1)
                        {
                            s[i] = '0';
                            a -= 2;
                        }
                    }
                    else
                    {
                        if (b > 1)
                        {
                            s[i] = '1';
                            b -= 2;
                        }
                    }
                }
                else
                {
                    if (s[i] == '0')
                    {
                        if (a > 1)
                        {
                            s[n - i - 1] = '0';
                            a -= 2;
                        }
                    }
                    else
                    {
                        if (b > 1)
                        {
                            s[n - i - 1] = '1';
                            b -= 2;
                        }
                    }
                }
            }
            if (s[i] != '?' && s[n - i - 1] != '?' && s[i] != s[n - i - 1])
                f = false;
        }
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] == '?' && s[i] == s[n - i - 1])
            {
                if (a >= b && a >= 2)
                {
                    s[i] = s[n - i - 1] = '0';
                    a -= 2;
                }
                else if (b >= a && b >= 2)
                {
                    s[i] = s[n - i - 1] = '1';
                    b -= 2;
                }
            }
        }
        if (n & 1)
        {
            if (s[n / 2] == '0')
                a--;
            else if (s[n / 2] == '1')
                b--;
            else
            {
                if (a > 0)
                    s[n / 2] = '0', a--;
                else if (b > 0)
                    s[n / 2] = '1', b--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                f = false;
                break;
            }
        }
        if (f && a == 0 && b == 0)
            cout << s << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
