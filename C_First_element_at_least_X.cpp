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
void build(int p, int tl, int tr)
{
    if (tl == tr)
    {
        t[p] = v[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(p * 2, tl, tm);
    build(p * 2 + 1, tm + 1, tr);
    t[p] = max(t[p * 2], t[p * 2 + 1]);
}
void update(int p, int tl, int tr, int i, ll x)
{
    if (tl == tr)
    {
        t[p] = x;
        return;
    }
    int tm = (tl + tr) / 2;
    if (i <= tm)
        update(p * 2, tl, tm, i, x);
    else
        update(p * 2 + 1, tm + 1, tr, i, x);
    t[p] = max(t[p * 2], t[p * 2 + 1]);
}
ll query(int p, int tl, int tr, ll x)
{
    if (tl == tr)
    {
        if (t[p] < x)
            return 0;
        return tl;
    }
    int tm = (tl + tr) / 2;
    if (t[p * 2] >= x)
        return query(p * 2, tl, tm, x);
    else
        return query(p * 2 + 1, tm + 1, tr, x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    v.resize(n + 1);
    t.resize(n * 4 + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    build(1, 1, n);
    while (m--)
    {
        ll a;
        cin >> a;
        if (a == 1)
        {
            ll i, x;
            cin >> i >> x;
            update(1, 1, n, i + 1, x);
        }
        else
        {
            ll x;
            cin >> x;
            cout << query(1, 1, n, x) - 1 << endl;
        }
    }
    return 0;
}
