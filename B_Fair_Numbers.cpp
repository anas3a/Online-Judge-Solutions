#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        while (true)
        {
            ll x = n;
            bool f = true;
            while (x != 0)
            {
                ll z = x % 10;
                x /= 10;
                if (z == 0)
                continue;
                if (n % z != 0)
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                cout << n << endl;
                break;
            }
            n++;
        }
    }
    return 0;
}
