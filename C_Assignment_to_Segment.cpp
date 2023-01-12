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

vll t;
void prop(int p, int tl, int tr)
{
    if (tl == tr)
        return;
    if (t[p] != -1)
    {
        t[p * 2] = t[p];
        t[p * 2 + 1] = t[p];
        t[p] = -1;
    }
}
void update(int p, int tl, int tr, int l, int r, ll x)
{
    prop(p, tl, tr);
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[p] = x;
        return;
    }
    int tm = (tl + tr) / 2;
    update(p * 2, tl, tm, l, min(r, tm), x);
    update(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
}
ll query(int p, int tl, int tr, int i)
{
    prop(p, tl, tr);
    if (tl == tr)
        return t[p];
    int tm = (tl + tr) / 2;
    if (i <= tm)
        return query(p * 2, tl, tm, i);
    else
        return query(p * 2 + 1, tm + 1, tr, i);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    t.assign(4 * (n + 1), 0);
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
            ll i;
            cin >> i;
            cout << query(1, 1, n, i + 1) << endl;
        }
    }
    return 0;
}
