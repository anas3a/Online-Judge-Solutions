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
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        vector<int> vx(n);
        vx = v;
        sort(vx.begin(), vx.end());
        ll z;
        if (vx[0] != vx[1])
            z = vx[0];
        else
            z = vx[n - 1];
        for (int i = 0; i < n; i++)
        {
            if (v[i] == z)
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}
