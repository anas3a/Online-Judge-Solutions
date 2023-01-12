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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        map<ll, ll> mp, mpx;
        for (int i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            mp[a]++;
        }
        for (auto &i : mp)
            mpx[i.ss]++;

        vpl v;
        for (auto &i : mpx)
            v.pb({i.ff, i.ss});

        vll vx(sz(v) + 1, 0);
        for (int i = 1; i <= sz(v); i++)
            vx[i] += vx[i - 1] + (v[i - 1].ss);

        ll ans = INT_MAX, sum = 0;
        for (int i = 0; i < sz(v); i++)
        {
            ll z = n - sum - (v[i].ff * v[i].ss);
            ans = min(ans, sum + (z - ((vx.back() - vx[i + 1]) * v[i].ff)));
            sum += (v[i].ff * v[i].ss);
        }
        cout << ans << endl;
    }
    return 0;
}