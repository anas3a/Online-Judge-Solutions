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

vll v, t;
void build(ll p, ll tl, ll tr, ll f)
{
    if (tl == tr)
    {
        t[p] = v[tl];
        return;
    }
    ll tm = (tl + tr) / 2;
    build(p * 2, tl, tm, 1 - f);
    build(p * 2 + 1, tm + 1, tr, 1 - f);
    if (f)
        t[p] = t[p * 2] | t[p * 2 + 1];
    else
        t[p] = t[p * 2] ^ t[p * 2 + 1];
}
void update(ll p, ll tl, ll tr, ll i, ll x, ll f)
{
    if (tl == tr)
    {
        t[p] = x;
        return;
    }
    ll tm = (tl + tr) / 2;
    if (i <= tm)
        update(p * 2, tl, tm, i, x, 1 - f);
    else
        update(p * 2 + 1, tm + 1, tr, i, x, 1 - f);
    if (f)
        t[p] = t[p * 2] | t[p * 2 + 1];
    else
        t[p] = t[p * 2] ^ t[p * 2 + 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, f = 0;
    cin >> n >> m;
    if (n & 1)
        f = 1;
    n = 1 << n;
    v.resize(n + 1);
    t.assign(4 * (n + 1), 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    build(1, 1, n, f);
    while (m--)
    {
        int p, b;
        cin >> p >> b;
        update(1, 1, n, p, b, f);
        cout << t[1] << endl;
    }
    return 0;
}
