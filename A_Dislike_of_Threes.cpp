#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll k;
        cin >> k;
        ll a = 1, cnt = 0;
        while (true)
        {
            if (a % 3 != 0 && a % 10 != 3)
                cnt++;
            if (cnt == k)
            {
                cout << a << endl;
                break;
            }
            a++;
        }
    }
    return 0;
}
