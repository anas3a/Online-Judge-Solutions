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
ll n, m;
void update(int p, int tl, int tr, int l, int r, ll x)
{
    if (l > r)
        return;
    if (tl >= l && tr <= r)
    {
        t[p] += x;
        return;
    }
    int tm = (tl + tr) / 2;
    update(p * 2, tl, tm, l, min(r, tm), x);
    update(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
}
ll query(int p, int tl, int tr, int i, ll val)
{
    if (tl == tr)
    {
        val += t[p];
        return val;
    }
    int tm = (tl + tr) / 2;
    if (i <= tm)
        return query(p * 2, tl, tm, i, val += t[p]);
    else
        return query(p * 2 + 1, tm + 1, tr, i, val += t[p]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    t.assign(4 * n + 1, 0);
    while (m--)
    {
        ll a;
        cin >> a;
        if (a == 1)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            l++;
            update(1, 1, n, l, r, x);
        }
        else
        {
            ll i;
            cin >> i;
            cout << query(1, 1, n, i + 1, 0) << endl;
        }
    }
    return 0;
}
