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
        ll n, x;
        cin >> n;
        x = n;
        while (true)
        {
            ll sum = 0;
            string s = to_string(x);
            for (int i = 0; i < s.size(); i++)
                sum += s[i] - '0';
            if (__gcd(x, sum) > 1)
            {
                cout << x << endl;
                break;
            }
            x++;
        }
    }
    return 0;
}
