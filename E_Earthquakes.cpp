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

ll n, m, cnt;
vll t;
void update(int p, int tl, int tr, int i, ll x)
{
    if (tl == tr)
    {
        t[p] = x;
        return;
    }
    int tm = (tl + tr) / 2;
    if (i <= tm)
        update(p * 2, tl, tm, i, x);
    else
        update(p * 2 + 1, tm + 1, tr, i, x);
    t[p] = min(t[p * 2], t[p * 2 + 1]);
}
void query(int p, int tl, int tr, int l, int r, ll px)
{
    if (l > r)
        return;
    if (t[p] > px)
        return;
    int tm = (tl + tr) / 2;
    if (tl == tr)
    {
        t[p] = 2e9;
        cnt++;
        return;
    }
    query(p * 2, tl, tm, l, min(r, tm), px);
    query(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r, px);
    t[p] = min(t[p * 2], t[p * 2 + 1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    t.resize(4 * (n + 1), 2e9);
    while (m--)
    {
        cnt = 0;
        int e;
        cin >> e;
        if (e == 1)
        {
            ll i, h;
            cin >> i >> h;
            update(1, 1, n, i + 1, h);
        }
        else
        {
            ll l, r, p;
            cin >> l >> r >> p;
            query(1, 1, n, l + 1, r, p);
            cout << cnt << endl;
        }
    }
    return 0;
}
