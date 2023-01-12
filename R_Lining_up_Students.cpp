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

vi t;
void build(int p, int tl, int tr)
{
    if (tl == tr)
    {
        t[p] = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    build(p * 2, tl, tm);
    build(p * 2 + 1, tm + 1, tr);
    t[p] = t[p * 2] + t[p * 2 + 1];
}
void update(int p, int tl, int tr, int x)
{
    if (tl == tr)
    {
        t[p] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    if (x <= tm)
        update(p * 2, tl, tm, x);
    else
        update(p * 2 + 1, tm + 1, tr, x);
    t[p] = t[p * 2] + t[p * 2 + 1];
}
int query(int p, int tl, int tr, int x)
{
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    if (t[p * 2 + 1] >= x)
        return query(p * 2 + 1, tm + 1, tr, x);
    else
        return query(p * 2, tl, tm, x - t[p * 2 + 1]);
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int tx, cs = 0;
    scanf("%d", &tx);
    while (tx--)
    {
        printf("Case %d: ", ++cs);
        int n;
        scanf("%d", &n);
        vi v(n);
        t.clear();
        t.resize(4 * n + 1);
        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        build(1, 1, n);
        reverse(all(v));
        int ans;
        for (int i = 0; i < n; i++)
        {
            ans = query(1, 1, n, v[i] + 1);
            update(1, 1, n, ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}