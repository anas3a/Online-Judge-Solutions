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

struct dt
{
    ll l, r, cost;
};
bool comp1(const dt &a, const dt &b)
{
    return a.r < b.l;
}
bool comp2(const dt &a, const dt &b)
{
    return a.l < b.l;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x;
    cin >> n >> x;
    vector<vector<dt>> v(x);
    for (int i = 0; i < n; i++)
    {
        dt tmp;
        cin >> tmp.l >> tmp.r >> tmp.cost;
        if (tmp.r - tmp.l + 1 >= x)
            continue;
        v[tmp.r - tmp.l + 1].pb(tmp);
    }
    vvi vx(x);
    for (int i = 1; i < x; i++)
    {
        sort(all(v[i]), comp2);
        vi tmp(sz(v[i]));
        vx[i] = tmp;
        ll mn = LLONG_MAX;
        for (int j = sz(vx[i]) - 1; j >= 0; j--)
        {
            mn = min(mn, v[i][j].cost);
            vx[i][j] = mn;
        }
    }
    ll ans = LLONG_MAX;
    for (int i = 1; i < x; i++)
    {
        ll z = x - i;
        for (int j = 0; j < v[i].size(); j++)
        {
            ll sum = v[i][j].cost;
            ll in = upper_bound(all(v[z]), v[i][j], comp1) - v[z].begin();
            if (in >= sz(v[z]))
                continue;
            sum += vx[z][in];
            ans = min(ans, sum);
        }
    }
    if (ans == LLONG_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
