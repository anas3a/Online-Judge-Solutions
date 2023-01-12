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

vll v, t;
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

ll query(int p, int tl, int tr, int l, int r)
{
    if (l > r)
        return INT_MAX;
    if (l == tl && r == tr)
        return t[p];
    int tm = (tl + tr) / 2;
    return min(query(p * 2, tl, tm, l, min(r, tm)), query(p * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll ts, cs = 0;
    scanf("%lld", &ts);
    while (ts--)
    {
        ll n, q;
        scanf("%lld %lld", &n, &q);
        printf("Case %lld:\n", ++cs);
        v.assign(n + 1, INT_MAX);
        t.assign(4 * n + 1, INT_MAX);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &v[i]);
        build(1, 1, n);
        while (q--)
        {
            ll a, b;
            scanf("%lld %lld", &a, &b);
            printf("%lld\n", query(1, 1, n, a, b));
        }
    }
    return 0;
}