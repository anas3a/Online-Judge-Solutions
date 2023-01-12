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

vll tx, t;
void push(int p, int tl, int tr)
{
    if (tl == tr)
        return;
    if (tx[p] != 0)
    {
        t[p * 2] += tx[p];
        t[p * 2 + 1] += tx[p];
        tx[p * 2] += tx[p];
        tx[p * 2 + 1] += tx[p];
        tx[p] = 0;
    }
}
void update(int p, int tl, int tr, int l, int r, ll x)
{
    if (l > r)
        return;
    push(p, tl, tr);
    if (tl == l && tr == r)
    {
        t[p] += x;
        tx[p] += x;
        return;
    }
    int tm = (tl + tr) / 2;
    update(p * 2, tl, tm, l, min(r, tm), x);
    update(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    t[p] = max(t[p * 2], t[p * 2 + 1]);
}
ll query(int p, int tl, int tr, ll x, int i)
{
    if (tr < i || t[p] < x)
        return 0;
    push(p, tl, tr);
    if (tl == tr)
    {
        if (t[p] < x)
            return 0;
        return tl;
    }
    int tm = (tl + tr) / 2;
    int res = 0;
    if (tm >= i || t[p * 2] >= x)
        res = query(p * 2, tl, tm, x, i);
    if (res == 0)
        res = query(p * 2 + 1, tm + 1, tr, x, i);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    t.resize(n * 4 + 1, 0);
    tx.resize(n * 4 + 1, 0);
    while (m--)
    {
        ll a;
        cin >> a;
        if (a == 1)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            update(1, 1, n, l + 1, r, x);
        }
        else
        {
            ll x, l;
            cin >> x >> l;
            cout << query(1, 1, n, x, l + 1) - 1 << '\n';
        }
    }
    return 0;
}
