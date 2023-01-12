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

vi v, t;
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
    t[p] = t[p * 2] + t[p * 2 + 1];
}
void update(int p, int tl, int tr, int i)
{
    if (tl == tr)
    {
        t[p] = 1 - t[p];
        return;
    }
    int tm = (tl + tr) / 2;
    if (i <= tm)
        update(p * 2, tl, tm, i);
    else
        update(p * 2 + 1, tm + 1, tr, i);
    t[p] = t[p * 2] + t[p * 2 + 1];
}
int query(int p, int tl, int tr, int k)
{
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    if (k <= t[p * 2])
        return query(p * 2, tl, tm, k);
    else
        return query(p * 2 + 1, tm + 1, tr, k - t[p * 2]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    v.resize(n + 1);
    t.resize(4 * n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    build(1, 1, n);
    while (m--)
    {
        int a, k;
        cin >> a >> k;
        if (a == 1)
            update(1, 1, n, k + 1);
        else
            cout << query(1, 1, n, k + 1) - 1  << endl;
    }
    return 0;
}
