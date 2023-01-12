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
    t[p] = t[p * 2] + t[p * 2 + 1];
}
void update(int p, int tl, int tr, int i, int x)
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
    t[p] = t[p * 2] + t[p * 2 + 1];
}
ll query(int p, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[p];
    int tm = (tl + tr) / 2;
    return query(p * 2, tl, tm, l, min(r, tm)) + query(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n;
    v.assign(n + 1, 0);
    t.assign(4 * n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i], v[i] = max(v[i], 0LL);
    cin >> m;
    build(1, 1, n);
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (!a)
        {
            c = max(0LL, c);
            update(1, 1, n, b, c);
        }
        else
            cout << query(1, 1, n, b, c) << endl;
    }

    return 0;
}
