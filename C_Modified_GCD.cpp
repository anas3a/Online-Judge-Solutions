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

    ll a, b;
    cin >> a >> b;
    ll x = __gcd(a, b);
    vll ans;
    for (ll i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            ans.pb(i);
            if (i != x / i)
                ans.pb(x / i);
        }
    }
    sort(all(ans));
    ll n;
    cin >> n;
    while (n--)
    {
        ll l, r;
        cin >> l >> r;
        ll z = lower_bound(all(ans), r) - ans.begin();
        if (z == sz(ans) || ans[z] > r)
            z--;
        if (z < 0 || ans[z] < l || ans[z] > r)
            cout << -1 << endl;
        else
            cout << ans[z] << endl;
    }
    return 0;
}
