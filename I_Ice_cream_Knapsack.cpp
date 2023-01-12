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

    freopen("icecream.in", "r", stdin);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        ll sum = 0;
        cin >> n >> k;
        vpl v(n);
        for (auto &i : v)
            cin >> i.ff;
        for (auto &i : v)
            cin >> i.ss;
        vll vx;
        sort(all(v));
        ll mx = -1;
        int i = 0;
        for (i = 0; i < sz(v) && i < k; i++)
        {
            vx.pb(v[i].ss);
            mx = max(v[i].ff, mx);
        }
        while (i < sz(v) && v[i].ff == mx)
        {
            vx.pb(v[i].ss);
            i++;
        }
        sort(rall(vx));
        for (int i = 0; i < k && i < sz(vx); i++)
            sum += vx[i];
        cout << mx << " " << sum << endl;
    }
    return 0;
}
