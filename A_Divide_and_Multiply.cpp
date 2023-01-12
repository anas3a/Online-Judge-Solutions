#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

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
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(all(v));
        while (true)
        {
            ll i = 0;
            ll j = n - 1;
            while (v[i] % 2)
                i++;
            while (v[j] % 2 == 0)
                j--;
            if (i > j)
                break;
            v[i] /= 2;
            v[j] *= 2;
            sort(all(v));
        }
        sort(all(v));
        for (int i = 0; i < n - 1; i++)
        {
            while (v[i] % 2 == 0)
            {
                v[n - 1] *= 2;
                v[i] /= 2;
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
            ans += v[i];
        cout << ans << endl;
    }
    return 0;
}