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
        int a[102];
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ll ans = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ll sum = a[i] + a[j] + j - i;
                ans = min(ans, sum);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
