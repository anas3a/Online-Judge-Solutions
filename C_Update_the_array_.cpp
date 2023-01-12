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
    if (tl == l && tr == r)
    {
        t[p] += x;
        return;
    }
    int tm = (tl + tr) / 2;
    update(p * 2, tl, tm, l, min(r, tm), x);
    update(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
}
ll query(int p, int tl, int tr, int i)
{
    if (tl == tr)
        return t[p];
    int tm = (tl + tr) / 2;
    ll tmp = 0;
    if (i <= tm)
        tmp = query(p * 2, tl, tm, i);
    else
        tmp = query(p * 2 + 1, tm + 1, tr, i);
    return t[p] + tmp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll tx;
    cin >> tx;
    while (tx--)
    {
        cin >> n >> m;
        t.clear();
        t.assign(4 * n + 1, 0);
        while (m--)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            l++;
            r++;
            update(1, 1, n, l, r, x);
        }
        cin >> m;
        while (m--)
        {
            ll i;
            cin >> i;
            cout << query(1, 1, n, i + 1) << endl;
        }
    }
    return 0;
}
