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

    ll n;
    cin >> n;
    vll vx;
    map<ll, ll> v;
    set<ll> st;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (!st.count(a))
            vx.pb(a), v[a] = INT_MAX, st.insert(a);
        v[a] = min(v[a], b);
    }
    ll q;
    cin >> q;
    sort(all(vx));
    while (q--)
    {
        ll x;
        cin >> x;
        ll ans = INT_MAX, dif = INT_MAX;
        ll ind = upper_bound(all(vx), x) - vx.begin();
        if (ind - 1 >= 0)
        {
            dif = abs(vx[ind - 1] - x);
            ans = v[vx[ind - 1]];
        }
        if (ind >= 0 && ind < sz(vx))
        {
            if (abs(vx[ind] - x) < dif)
            {
                dif = abs(vx[ind] - x);
                ans = v[vx[ind]];
            }
            else if (abs(vx[ind] - x) == dif)
            {
                ans = min(ans, v[vx[ind]]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}