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

vll t, tx;
void update(int p, int tl, int tr, int l, int r, ll x)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[p] += (r - l + 1) * x;
        tx[p] += x;
        return;
    }
    int tm = (tl + tr) / 2;
    update(p * 2, tl, tm, l, min(r, tm), x);
    update(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    t[p] = (t[p * 2] + t[p * 2 + 1]) + (tx[p] * (tr - tl + 1));
}
ll query(int p, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[p];
    int tm = (tl + tr) / 2;
    return (query(p * 2, tl, tm, l, min(r, tm)) +
            query(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r) +
            (tx[p] * (min(tr, r) - max(tl, l) + 1)));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    t.assign(4 * (n + 1), 0);
    tx.assign(4 * (n + 1), 0);
    while (m--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            update(1, 1, n, l + 1, r, x);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l + 1, r) << endl;
        }
    }
    return 0;
}
