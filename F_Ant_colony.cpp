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
    ll mn = 2e9;
    ll mcnt = 0;
    ll cnt = 0;
    ll gcd = 0;
};
vll v;
vector<dt> t;
dt z;
dt mrg(const dt &a, const dt &b)
{
    dt c;
    if (a.mn < b.mn)
    {
        c.mn = a.mn;
        c.mcnt = a.mcnt;
    }
    else if (b.mn < a.mn)
    {
        c.mn = b.mn;
        c.mcnt = b.mcnt;
    }
    else
    {
        c.mn = a.mn;
        c.mcnt = a.mcnt + b.mcnt;
    }
    c.cnt = a.cnt + b.cnt;
    c.gcd = __gcd(a.gcd, b.gcd);
    return c;
}
void build(int p, int tl, int tr)
{
    if (tl == tr)
    {
        t[p].mn = t[p].gcd = v[tl];
        t[p].mcnt = t[p].cnt = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    build(p * 2, tl, tm);
    build(p * 2 + 1, tm + 1, tr);
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

    int n;
    cin >> n;
    v.resize(n + 1);
    t.resize(4 * (n + 1));
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    build(1, 1, n);
    int m;
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        dt ans = query(1, 1, n, l, r);
        int a = 0;
        if (ans.gcd == ans.mn)
            a = ans.mcnt;
        cout << ans.cnt - a << endl;
    }
    return 0;
}
