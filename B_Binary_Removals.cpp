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
        string s;
        cin >> s;
        bool fm = true, fn = true, fx = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                fx = true;
            if (fx && i > 0 && s[i] == '0' && s[i - 1] == '0')
            {
                fm = false;
                break;
            }
        }
        fx = true;
        for (int i = s.size() - 1; i > 0; i--)
        {
            if (s[i] == '0')
                fx = true;
            if (fx && s[i] == '1' && s[i - 1] == '1')
            {
                fn = false;
                break;
            }
        }
        if (fm || fn)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
