#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;

        vll v(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            v[s[i] - 'a'] = i + 1;
        }
        ll ans = 0;
        ll z = v[t[0] - 'a'];
        for (int i = 0; i < t.size(); i++)
        {
            if (i == 0)
                continue;
            ans += abs(z - v[t[i] - 'a']);
            z = v[t[i] - 'a'];
        }
        cout << ans << endl;
    }

    return 0;
}