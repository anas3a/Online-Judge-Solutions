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
    int id = 0;
    int cnt = 0;
    int ind = 0;
};
vi v;
vector<dt> t;
void build(int p, int tl, int tr)
{
    if (tl == tr)
    {
        if (tl <= sz(v))
        {
            t[p].id = v[tl];
            t[p].cnt = 1;
            t[p].ind = tl;
        }
        else
        {
            t[p].id = 0;
            t[p].cnt = 0;
            t[p].ind = tl;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    build(p * 2, tl, tm);
    build(p * 2 + 1, tm + 1, tr);
    t[p].cnt = t[p * 2].cnt + t[p * 2 + 1].cnt;
}
void update(int p, int tl, int tr, int x, int val)
{
    if (tl == tr)
    {
        if (val == 0)
            t[p].cnt = val;
        else
        {
            t[p].cnt = 1;
            t[p].id = val;
            t[p].ind = tl;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    if (x <= tm)
        update(p * 2, tl, tm, x, val);
    else
        update(p * 2 + 1, tm + 1, tr, x, val);
    t[p].cnt = t[p * 2].cnt + t[p * 2 + 1].cnt;
}
dt query(int p, int tl, int tr, int x)
{
    if (tl == tr)
        return t[p];
    int tm = (tl + tr) / 2;
    if (x <= t[p * 2].cnt)
        return query(p * 2, tl, tm, x);
    else
        return query(p * 2 + 1, tm + 1, tr, x - t[p * 2].cnt);
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int tx, cs = 0;
    scanf("%d", &tx);
    while (tx--)
    {
        printf("Case %d:\n", ++cs);
        int n, q;
        scanf("%d %d", &n, &q);
        int nx = 2e5;
        v.clear();
        v.resize(n + 1);
        t.clear();
        t.resize(4 * nx + 1);
        for (int i = 1; i <= n; i++)
            scanf("%d", &v[i]);
        build(1, 1, nx);
        int cnt = n;
        while (q--)
        {
            char c;
            scanf(" %c", &c);
            if (c == 'c')
            {
                int p;
                scanf("%d", &p);
                if (p > cnt)
                    printf("none\n");
                else
                {
                    cnt--;
                    dt ans = query(1, 1, nx, p);
                    printf("%d\n", ans.id);
                    update(1, 1, nx, ans.ind, 0);
                }
            }
            else
            {
                cnt++;
                n++;
                int p;
                scanf("%d", &p);
                v.pb(p);
                update(1, 1, nx, n, p);
            }
        }
    }
    return 0;
}