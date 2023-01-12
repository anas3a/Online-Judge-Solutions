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

vi t, tx;
void prop(int p, int tl, int tr)
{
    if (tl == tr)
        return;
    if (tx[p] & 1)
    {
        tx[p * 2]++;
        tx[p * 2 + 1]++;
        int tm = (tl + tr) / 2;
        t[p * 2] = (tm - tl + 1) - t[p * 2];
        t[p * 2 + 1] = (tr - tm) - t[p * 2 + 1];
        tx[p] = 0;
    }
}
void update(int p, int tl, int tr, int l, int r)
{
    prop(p, tl, tr);
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[p] = (tr - tl + 1) - t[p];
        tx[p] += 1;
        return;
    }
    int tm = (tl + tr) / 2;
    update(p * 2, tl, tm, l, min(r, tm));
    update(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    t[p] = t[p * 2] + t[p * 2 + 1];
}
int query(int p, int tl, int tr, int k)
{
    prop(p, tl, tr);
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    if (k <= t[p * 2])
        return query(p * 2, tl, tm, k);
    else
        return query(p * 2 + 1, tm + 1, tr, k - t[p * 2]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    tx.resize(4 * n + 1, 0);
    t.resize(4 * n + 1, 0);
    while (m--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int l, r;
            cin >> l >> r;
            update(1, 1, n, l + 1, r);
        }
        else
        {
            int k;
            cin >> k;
            cout << query(1, 1, n, k + 1) - 1 << endl;
        }
    }
    return 0;
}
