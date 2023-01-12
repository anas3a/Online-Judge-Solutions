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

vll t, v;
int cnt;
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
    t[p] = __gcd(t[p * 2], t[p * 2 + 1]);
}
void update(int p, int tl, int tr, int i, int x)
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
    t[p] = __gcd(t[p * 2], t[p * 2 + 1]);
}
bool query(int p, int tl, int tr, int l, int r, ll x)
{
    if (l > r)
        return true;
    if (tl == l && tr == r && t[p] % x == 0)
        return true;
    if (tl == tr)
    {
        if (t[p] % x != 0)
            cnt++;
        return true;
    }
    int tm = (tl + tr) / 2;
    if (tl == l && tr == r)
    {
        if (t[p * 2] % x != 0 && t[p * 2 + 1] % x != 0)
            return false;
        if (t[p * 2] % x == 0)
            return query(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
        else
            return query(p * 2, tl, tm, l, min(r, tm), x);
    }
    return query(p * 2, tl, tm, l, min(r, tm), x) &&
           query(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    t.resize(4 * (n + 1));
    v.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    build(1, 1, n);
    int m;
    cin >> m;
    while (m--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            cnt = 0;
            if (query(1, 1, n, l, r, x) && cnt <= 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            ll i, y;
            cin >> i >> y;
            update(1, 1, n, i, y);
        }
    }
    return 0;
}
