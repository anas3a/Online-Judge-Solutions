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

vll t, tx, v;
void prop(int p, int tl, int tr)
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
void update(int p, int tl, int tr, int l, int r, int x)
{
    if (l > r)
        return;
    prop(p, tl, tr);
    if (tl == l && tr == r)
    {
        tx[p] += x;
        t[p] += x;
        return;
    }
    int tm = (tl + tr) / 2;
    update(p * 2, tl, tm, l, min(r, tm), x);
    update(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    t[p] = min(t[p * 2], t[p * 2 + 1]);
}
ll query(int p, int tl, int tr, int l, int r)
{
    if (l > r)
        return LLONG_MAX;
    prop(p, tl, tr);
    if (tl == l && tr == r)
        return t[p];
    int tm = (tl + tr) / 2;
    return min(query(p * 2, tl, tm, l, min(r, tm)),
               query(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    v.resize(n + 1);
    t.resize(4 * (n + 1), 0);
    tx.resize(4 * (n + 1), 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    build(1, 1, n);
    cin >> m;
    while (m--)
    {
        int l, r, x;
        cin >> l >> r;
        l++, r++;
        if (cin.peek() != '\n')
        {
            cin >> x;
            if (l <= r)
                update(1, 1, n, l, r, x);
            else
            {
                update(1, 1, n, 1, r, x);
                update(1, 1, n, l, n, x);
            }
        }
        else
        {
            if (l <= r)
                cout << query(1, 1, n, l, r) << endl;
            else
                cout << min(query(1, 1, n, 1, r),
                            query(1, 1, n, l, n))
                     << endl;
        }
    }
    return 0;
}
