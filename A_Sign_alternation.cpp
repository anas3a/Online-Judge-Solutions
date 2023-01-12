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

vll v, t1, t2, v1, v2;
void build1(int p, int tl, int tr)
{
    if (tl == tr)
    {
        t1[p] = v1[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build1(p * 2, tl, tm);
    build1(p * 2 + 1, tm + 1, tr);
    t1[p] = t1[p * 2] + t1[p * 2 + 1];
}
void build2(int p, int tl, int tr)
{
    if (tl == tr)
    {
        t2[p] = v2[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build2(p * 2, tl, tm);
    build2(p * 2 + 1, tm + 1, tr);
    t2[p] = t2[p * 2] + t2[p * 2 + 1];
}
void update1(int p, int tl, int tr, int i, int x)
{
    if (tl == tr)
    {
        t1[p] = x;
        return;
    }
    int tm = (tl + tr) / 2;
    if (i <= tm)
        update1(p * 2, tl, tm, i, x);
    else
        update1(p * 2 + 1, tm + 1, tr, i, x);
    t1[p] = t1[p * 2] + t1[p * 2 + 1];
}
void update2(int p, int tl, int tr, int i, int x)
{
    if (tl == tr)
    {
        t2[p] = x;
        return;
    }
    int tm = (tl + tr) / 2;
    if (i <= tm)
        update2(p * 2, tl, tm, i, x);
    else
        update2(p * 2 + 1, tm + 1, tr, i, x);
    t2[p] = t2[p * 2] + t2[p * 2 + 1];
}
ll query1(int p, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t1[p];
    int tm = (tl + tr) / 2;
    return query1(p * 2, tl, tm, l, min(r, tm)) + query1(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
ll query2(int p, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t2[p];
    int tm = (tl + tr) / 2;
    return query2(p * 2, tl, tm, l, min(r, tm)) + query2(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n;
    v.assign(n + 1, 0);
    v1.assign(n + 1, 0);
    v2.assign(n + 1, 0);
    t1.assign(4 * n + 1, 0);
    t2.assign(4 * n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
            v1[i] = v[i];
        else
            v1[i] = -v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
            v2[i] = -v[i];
        else
            v2[i] = v[i];
    }
    cin >> m;
    build1(1, 1, n);
    build2(1, 1, n);
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
        {
            if (b & 1)
            {
                update1(1, 1, n, b, c);
                update2(1, 1, n, b, -c);
            }
            else
            {
                update1(1, 1, n, b, -c);
                update2(1, 1, n, b, c);
            }
        }
        else
        {
            if (b & 1)
                cout << query1(1, 1, n, b, c) << endl;
            else
                cout << query2(1, 1, n, b, c) << endl;
        }
    }

    return 0;
}
