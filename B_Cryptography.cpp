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

ll md, n, m;
struct dt
{
    ll arr[2][2];
};
dt z;
vector<dt> v, t;
dt mul(const dt &a, const dt &b)
{
    dt c;
    memset(c.arr, 0, sizeof(c.arr));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                c.arr[i][j] += (a.arr[i][k] * b.arr[k][j]) % md;
                c.arr[i][j] %= md;
            }
        }
    }
    return c;
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
    t[p] = mul(t[p * 2], t[p * 2 + 1]);
}
dt query(int p, int tl, int tr, int l, int r)
{
    if (l > r)
        return z;
    if (tl == l && tr == r)
        return t[p];
    int tm = (tl + tr) / 2;
    return mul(query(p * 2, tl, tm, l, min(r, tm)),
               query(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> md >> n >> m;
    v.resize(n + 1);
    t.resize(4 * n + 1);
    z.arr[0][0] = 1, z.arr[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        dt a;
        cin >> a.arr[0][0] >> a.arr[0][1] >> a.arr[1][0] >> a.arr[1][1];
        v[i] = a;
    }
    build(1, 1, n);
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        dt a = query(1, 1, n, l, r);
        cout << a.arr[0][0] << " " << a.arr[0][1] << '\n'
             << a.arr[1][0] << " " << a.arr[1][1] << '\n';
        cout << '\n';
    }
    return 0;
}
