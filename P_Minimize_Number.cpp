#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    int a[300];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    while (true)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
                a[i] /= 2;
            else
                cnt++;
        }
        if (cnt == 0)
            ans++;
        else
            break;
    }
    cout << ans << endl;
    return 0;
}
