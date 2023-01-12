#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        ll a, b, m;
        cin >> a >> b >> m;
        bool f = false;
        ll cnt = 0;
        for (ll i = 0; i <= min(99999ll, m); i++)
        {
            if (i == m)
                f = true;
            if (__gcd(a + i, b + i) == 1)
                cnt++;
        }
        if (f)
            printf("Case %d: %lld\n", ++cs, cnt);
        else
        {
            ll z = m % 99999;
            ll ans = cnt * (m / 99999);
            for (ll i = ((m / 99999) * 99999) + 1; i <= m; i++)
            {
                if (__gcd(a + i, b + i) == 1)
                    ans++;
            }
            printf("Case %d: %lld\n", ++cs, ans);
        }
    }
    return 0;
}
