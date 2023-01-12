#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector <int>;
using vll = vector <ll>;
using vvi = vector <vi >;
using pii = pair <int, int>;
using pll = pair <long, long>;
using vpi = vector <pii >;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, mx = -1, ans;
        cin >> n;
        vll v(n);
        set <ll> s;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            s.insert(v[i]);
            mx = max(mx, v[i]);
        }
        if (s.size() == 1)
        cout << -1 << endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] == mx)
                {
                    if (i != 0 && v[i - 1] < mx)
                    {
                        ans = i + 1;
                        break;
                    }
                    if (i != n - 1 && v[i + 1] < mx)
                    {
                        ans = i + 1;
                        break;
                    }
                }
            }
            cout << ans << endl;
        }
        
    }
    return 0;
}
