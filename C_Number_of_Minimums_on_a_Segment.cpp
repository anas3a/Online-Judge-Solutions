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

vll v;
vpl t;
pll func(pll a, pll b)
{
    if (a.ff < b.ff)
        return a;
    if (b.ff < a.ff)
        return b;
    return {a.ff, a.ss + b.ss};
}
void build(int p, int tl, int tr)
{
    if (tl == tr)
    {
        t[p] = {v[tl], 1};
        return;
    }
    int tm = (tl + tr) / 2;
    build(p * 2, tl, tm);
    build(p * 2 + 1, tm + 1, tr);
    t[p] = func(t[p * 2], t[p * 2 + 1]);
}
void update(int p, int tl, int tr, int i, ll x)
{
    if (tl == tr)
    {
        t[p] = {x, 1};
        return;
    }
    int tm = (tl + tr) / 2;
    if (i <= tm)
        update(p * 2, tl, tm, i, x);
    else
        update(p * 2 + 1, tm + 1, tr, i, x);
    t[p] = func(t[p * 2], t[p * 2 + 1]);
}
pll query(int p, int tl, int tr, int l, int r)
{
    if (l > r)
        return {LLONG_MAX, 0};
    if (tl == l && tr == r)
        return t[p];
    int tm = (tl + tr) / 2;
    return func(query(p * 2, tl, tm, l, min(r, tm)), query(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    v.resize(n + 1);
    t.resize(4 * n + 1, {LLONG_MAX, 0});
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    build(1, 1, n);
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(1, 1, n, b + 1, c);
        else
        {
            pll ans = query(1, 1, n, b + 1, c);
            cout << ans.ff << " " << ans.ss << endl;
        }
    }
    return 0;
}
