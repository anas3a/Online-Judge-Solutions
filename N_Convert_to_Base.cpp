#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ll t;
    cin >> t;
    if (t == 1)
    {
        string s;
        ll x;
        cin >> s >> x;
        ll z = 1;
        ll ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ans *= x;
            if (s[i] <= '9')
                z = s[i] - '0';
            else
                z = s[i] - 'A' + 10;
            ans += z;
        }
        cout << ans << endl;
    }
    else
    {
        ll n, x;
        cin >> n >> x;
        string ans;
        while (n != 0)
        {
            ll z = n % x;
            if (z <= 9)
                ans = to_string(z) + ans;
            else
                ans = char('A' + (z - 10)) + ans;
            n /= x;
        }
        cout << ans << endl;
    }
    return 0;
}
