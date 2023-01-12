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
    ll seg, sum, pref, suf;
};
vll v;
vector<dt> t;
dt com(dt a, dt b)
{
    dt res;
    res.sum = a.sum + b.sum;
    res.pref = max(a.pref, a.sum + b.pref);
    res.suf = max(b.suf, b.sum + a.suf);
    res.seg = max({a.seg, b.seg, a.suf + b.pref});
    return res;
}
dt make(ll x)
{
    dt res;
    res.sum = x;
    res.seg = res.pref = res.suf = max(0LL, x);
    return res;
}
void build(int p, int tl, int tr)
{
    if (tl == tr)
    {
        t[p] = make(v[tl]);
        return;
    }
    int tm = (tl + tr) / 2;
    build(p * 2, tl, tm);
    build(p * 2 + 1, tm + 1, tr);
    t[p] = com(t[p * 2], t[p * 2 + 1]);
}
void update(int p, int tl, int tr, int i, int x)
{
    if (tl == tr)
    {
        t[p] = make(x);
        return;
    }
    int tm = (tl + tr) / 2;
    if (i <= tm)
        update(p * 2, tl, tm, i, x);
    else
        update(p * 2 + 1, tm + 1, tr, i, x);
    t[p] = com(t[p * 2], t[p * 2 + 1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    v.resize(n + 1);
    t.resize(4 * n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    build(1, 1, n);
    cout << t[1].seg << endl;
    while (m--)
    {
        ll i, x;
        cin >> i >> x;
        update(1, 1, n, i + 1, x);
        cout << t[1].seg << endl;
    }
    return 0;
}
