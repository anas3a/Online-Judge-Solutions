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
    int c1 = 0, c2 = 0, c0 = 0;
};
vector<dt> v;
vi vx;
dt mrg(dt &a, dt &b)
{
    dt tmp;
    tmp.c0 = a.c0 + b.c0;
    tmp.c1 = a.c1 + b.c1;
    tmp.c2 = a.c2 + b.c2;
    return tmp;
}
void rotate(dt &a)
{
    int tmp = a.c0;
    a.c0 = a.c2;
    a.c2 = a.c1;
    a.c1 = tmp;
}

void build(int p, int tl, int tr)
{
    if (tl == tr)
    {
        v[p].c0 = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    build(p * 2, tl, tm);
    build(p * 2 + 1, tm + 1, tr);
    v[p] = mrg(v[p * 2], v[p * 2 + 1]);
}

void push(int p, int tl, int tr)
{
    if (tl == tr)
        return;
    if (vx[p] != 0)
    {
        if (vx[p] % 3)
            rotate(v[p * 2]), rotate(v[p * 2 + 1]);
        if (vx[p] % 3 == 2)
            rotate(v[p * 2]), rotate(v[p * 2 + 1]);
        vx[p * 2] += vx[p];
        vx[p * 2 + 1] += vx[p];
        vx[p] = 0;
    }
}
void update(int p, int tl, int tr, int l, int r)
{
    push(p, tl, tr);
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        rotate(v[p]);
        vx[p]++;
        return;
    }
    int tm = (tl + tr) / 2;
    update(p * 2, tl, tm, l, min(tm, r));
    update(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    v[p] = mrg(v[p * 2], v[p * 2 + 1]);
}

int query(int p, int tl, int tr, int l, int r)
{
    push(p, tl, tr);
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return v[p].c0;
    int tm = (tl + tr) / 2;
    return query(p * 2, tl, tm, l, min(r, tm)) +
           query(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        cout << "Case " << ++cs << ":" << '\n';
        v.clear();
        vx.clear();
        v.resize(4 * n + 1);
        vx.resize(4 * n + 1, 0);
        build(1, 1, n);
        while (q--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            b++, c++;
            if (!a)
                update(1, 1, n, b, c);
            else
                cout << query(1, 1, n, b, c) << '\n';
        }
    }
    return 0;
}