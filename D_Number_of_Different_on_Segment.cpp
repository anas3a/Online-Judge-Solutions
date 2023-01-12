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
    ll fre[41];
    ll cnt = 0;
};
vi v;
vector<dt> t;
ll n, q;
dt z;
dt mrg(const dt &a, const dt &b)
{
    dt c = z;
    for (int i = 1; i <= 40; i++)
    {
        if (a.fre[i] + b.fre[i] >= 1)
        {
            c.fre[i] = 1;
            c.cnt++;
        }
    }
    return c;
}
void build(int p, int tl, int tr)
{
    if (tl == tr)
    {
        t[p].fre[v[tl]] = 1;
        t[p].cnt = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    build(p * 2, tl, tm);
    build(p * 2 + 1, tm + 1, tr);
    t[p] = mrg(t[p * 2], t[p * 2 + 1]);
}
void update(int p, int tl, int tr, int pos, int x)
{
    if (tl == tr)
    {
        for (int i = 1; i <= 40; i++)
        {
            if (i == x)
                t[p].fre[i] = 1;
            else
                t[p].fre[i] = 0;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        update(p * 2, tl, tm, pos, x);
    else
        update(p * 2 + 1, tm + 1, tr, pos, x);
    t[p] = mrg(t[p * 2], t[p * 2 + 1]);
}
dt query(int p, int tl, int tr, int l, int r)
{
    if (l > r)
        return z;
    if (tl == l && tr == r)
        return t[p];
    int tm = (tl + tr) / 2;
    return mrg(query(p * 2, tl, tm, l, min(r, tm)),
               query(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    v.resize(n + 1);
    t.resize(4 * (n + 1));

    for (int i = 1; i <= n; i++)
        cin >> v[i];
    build(1, 1, n);
    while (q--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            cout << query(1, 1, n, b, c).cnt << endl;
        else
            update(1, 1, n, b, c);
    }
    return 0;
}
