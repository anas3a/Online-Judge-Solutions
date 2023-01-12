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
    vll v(n), vx;
    for (auto &i : v)
        cin >> i;
    ll x = *min_element(all(v));
    ll ans = x * n;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
            vx.pb(i);
    }
    ll mx = 0;
    for (int i = 1; i < sz(vx); i++)
        mx = max(vx[i] - vx[i - 1] - 1, mx);
    mx = max(n - vx[sz(vx) - 1] + vx[0] - 1, mx);
    cout << ans + mx << endl;
    return 0;
}
