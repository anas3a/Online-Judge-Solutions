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
        ll n, w, sum = 0;
        cin >> n >> w;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            sum += log2(x);
        }
        ll z = floor(log2(w));
        ll ans = sum / z;
        // if (sum % z)
        //     ans++;
        cout << ans << endl;
    }
    return 0;
}
