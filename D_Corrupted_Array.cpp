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
        ll n;
        cin >> n;
        ll sum = 0;
        vector<long long> v(n + 2);
        for (auto &i : v)
            cin >> i, sum += i;
        sort(v.rbegin(), v.rend());
        bool f = false;
        if (sum - v[0] == 2 * v[1])
        {
            f = true;
            for (int i = 2; i < n + 2; i++)
                cout << v[i] << " ";
            cout << endl;
        }
        else
        {
            sum -= v[0];
            for (int i = 1; i < n + 2; i++)
            {
                ll z = sum - v[i];
                if (z == v[0])
                {
                    f = true;
                    for (int j = 1; j < n + 2; j++)
                    {
                        if (j == i)
                            continue;
                        cout << v[j] << " ";
                    }
                    cout << endl;
                    break;
                }
            }
        }
        if (!f)
            cout << -1 << endl;
    }
    return 0;
}
