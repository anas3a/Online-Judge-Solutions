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

ll n, s;
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
    t[p] = min(t[p * 2], t[p * 2 + 1]);
}
ll query(int p, int tl, int tr, int l, int r)
{
    if (l > r)
        return INT_MAX;
    if (tl == l && tr == r)
        return t[p];
    int tm = (tl + tr) / 2;
    return min(query(p * 2, tl, tm, l, min(r, tm)),
               query(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
bool ok(ll m)
{
    for (int i = 1; i + m <= n; i++)
    {
        ll minval = query(1, 1, n, i, i + m);
        if (minval + s >= 0)
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ts;
    cin >> ts;
    while (ts--)
    {
        cin >> n >> s;
        v.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            v[i] += v[i - 1];
        }
        t.clear();
        t.resize(4 * n + 1);
        build(1, 1, n);
        ll l = -1, r = n + 10;
        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (ok(m))
                l = m;
            else
                r = m;
        }
        cout << l << endl;
    }
    return 0;
}