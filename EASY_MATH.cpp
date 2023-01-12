#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpi = vector<pii>;
using vpl = vector<pll>;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) ((int)(v).size())
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, a, d, ans;
        cin >> n >> m >> a >> d;
        ans = m - n + 1;
        vll v;
        v.pb(a);
        for (int i = 1; i <= 4; i++)
        {
            v.pb(a + (i * d));
        }
        for (ll i = 0; i < (1 << 5); i++)
        {
            ll x = 0, cnt = 0;
            for (int j = 0; j < 5; j++)
            {
                if (i & (1 << j))
                {
                    if (x == 0)
                        x = v[j];
                    else
                        x = (x / __gcd(x, v[j])) * v[j];
                    cnt++;
                }
            }
            if (cnt)
            {
                ll z = m / x;
                z -= (n - 1) / x;
                if (cnt & 1)
                    ans -= z;
                else
                    ans += z;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
