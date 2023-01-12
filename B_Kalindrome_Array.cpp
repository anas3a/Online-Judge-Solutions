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
        ll n;
        cin >> n;
        vll v(n);
        for (auto &i : v)
            cin >> i;
        ll x = -1, y = -1;
        for (int i = 0, j = n - 1; i != j; i++, j--)
        {
            if (v[i] != v[j])
            {
                x = v[i];
                y = v[j];
                break;
            }
        }
        if (x == -1 && y == -1)
            cout << "YES" << endl;
        else
        {
            ll i = 0, j = n - 1;
            bool flag1 = true, flag2 = true;
            while (i < j)
            {
                if (v[i] != v[j])
                {
                    if (v[i] == x)
                        i++;
                    else if (v[j] == x)
                        j--;
                    else
                    {
                        flag1 = false;
                        break;
                    }
                }
                else
                {
                    i++;
                    j--;
                }
            }
            i = 0, j = n - 1;
            while (i < j)
            {
                if (v[i] != v[j])
                {
                    if (v[i] == y)
                        i++;
                    else if (v[j] == y)
                        j--;
                    else
                    {
                        flag2 = false;
                        break;
                    }
                }
                else
                {
                    i++;
                    j--;
                }
            }
            if (flag1 || flag2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}