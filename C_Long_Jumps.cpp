#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n), vx(n, 0);
        for (auto &i : v)
            cin >> i;
        for (int i = n - 1; i >= 0; i--)
        {
            vx[i] = v[i];
            if (i + v[i] < n)
                vx[i] += vx[i + v[i]];
        }
        sort(vx.rbegin(), vx.rend());
        cout << vx[0] << endl;
    }
}
