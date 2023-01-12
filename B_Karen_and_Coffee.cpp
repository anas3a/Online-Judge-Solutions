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

    ll n, k, q;
    cin >> n >> k >> q;
    vll vb, ve;
    for (int i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        vb.pb(l);
        ve.pb(r);
    }
    sort(all(vb));
    sort(all(ve));
    vll vx(200002, 0);
    ll cnt = 0;
    for (int i = vb.front(); i <= ve.back(); i++)
    {
        if (binary_search(all(vb), i))
        {
            ll x = lower_bound(all(vb), i) - vb.begin();
            ll y = upper_bound(all(vb), i) - vb.begin();
            cnt += y - x;
        }
        if (binary_search(all(ve), i - 1))
        {
            ll x = lower_bound(all(ve), i - 1) - ve.begin();
            ll y = upper_bound(all(ve), i - 1) - ve.begin();
            cnt -= y - x;
        }
        vx[i] = cnt;
    }
    vll vans(200002, 0);
    for (int i = 1; i <= sz(vans); i++)
    {
        vans[i] += vans[i - 1];
        if (vx[i] >= k)
            vans[i]++;
    }
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        cout << vans[b] - vans[a - 1] << endl;
    }
    return 0;
}
