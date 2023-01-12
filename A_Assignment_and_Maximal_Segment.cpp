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
vector<dt> t;
vll tx;
dt mrg(const dt &a, const dt &b)
{
    dt c;
    c.sum = a.sum + b.sum;
    c.pref = max(a.pref, a.sum + b.pref);
    c.suf = max(b.suf, b.sum + a.suf);
    c.seg = max({a.seg, b.seg, a.suf + b.pref});
    return c;
}
void push(int p, int tl, int tr)
{
    if (tl == tr)
        return;
    if (tx[p] != LLONG_MIN)
    {
        tx[p * 2] = tx[p * 2 + 1] = tx[p];
        int tm = (tl + tr) / 2;
        t[p * 2].sum = tx[p] * (tm - tl + 1);
        t[p * 2 + 1].sum = tx[p] * (tr - tm);
        t[p * 2].pref = t[p * 2].suf = t[p * 2].seg = max(t[p * 2].sum, 0LL);
        t[p * 2 + 1].pref = t[p * 2 + 1].suf = t[p * 2 + 1].seg = max(t[p * 2 + 1].sum, 0LL);
        tx[p] = LLONG_MIN;
    }
}
void update(int p, int tl, int tr, int l, int r, ll x)
{
    push(p, tl, tr);
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        tx[p] = x;
        t[p].sum = x * (tr - tl + 1);
        t[p].pref = t[p].suf = t[p].seg = max(t[p].sum, 0LL);
        return;
    }
    int tm = (tl + tr) / 2;
    update(p * 2, tl, tm, l, min(r, tm), x);
    update(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    t[p] = mrg(t[p * 2], t[p * 2 + 1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    t.resize(4 * (n + 1));
    tx.resize(4 * (n + 1));
    while (m--)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        update(1, 1, n, l + 1, r, x);
        cout << t[1].seg << endl;
    }
    return 0;
}
