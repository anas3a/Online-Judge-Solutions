#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L' || s[i] == 'R')
                continue;
            if (s[i] == 'U')
                s[i] = 'D';
            else if (s[i] == 'D')
                s[i] = 'U';
        }
        cout << s << endl;
    }
    return 0;
}
