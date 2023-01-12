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

    ll n, k;
    cin >> n >> k;
    vi v(n);
    for (auto &i : v)
        cin >> i;
    vpi vx;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 100)
            vx.pb({-1, i});
        else
            vx.pb({v[i] % 10, i});
    }
    sort(rall(vx));
    for (int i = 0; i < sz(vx); i++)
    {
        if (vx[i].ff == -1)
            continue;
        int x = 10 - vx[i].ff;
        if (x <= k)
        {
            k -= x;
            v[vx[i].ss] += x;
        }
        else
            break;
    }
    ll ans = 0;
    for (int i = 0; i < sz(v); i++)
    {
        while (k >= 10 && v[i] < 100)
        {
            k -= 10;
            v[i] += 10;
        }
        ans += v[i] / 10;
    }
    cout << ans << endl;
    return 0;
}
