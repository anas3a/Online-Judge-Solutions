#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0;
        cin >> n;
        int a[200];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int l = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                ll x = i - l + 1;
                cnt += x * (x + 1) / 2;
                l = i + 1;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
