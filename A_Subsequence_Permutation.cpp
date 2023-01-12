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
        string s, t;
        cin >> n >> s;
        t = s;
        sort(t.begin(), t.end());
        ll cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != t[i])
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
