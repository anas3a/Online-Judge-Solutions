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

vi v, t, ans;
int n;
void build(int p, int tl, int tr)
{
    if (tl == tr)
    {
        if (tl == n)
            t[p] = 0;
        else
            t[p] = 1;
        return;
    }
    ll tm = (tl + tr) / 2;
    build(p * 2, tl, tm);
    build(p * 2 + 1, tm + 1, tr);
    t[p] = t[p * 2] + t[p * 2 + 1];
}
void update(int p, int tl, int tr, int i)
{
    if (tl == tr)
    {
        t[p] = 0;
        return;
    }
    ll tm = (tl + tr) / 2;
    if (i <= tm)
        update(p * 2, tl, tm, i);
    else
        update(p * 2 + 1, tm + 1, tr, i);
    t[p] = t[p * 2] + t[p * 2 + 1];
}
int query(int p, int tl, int tr, int x)
{
    if (tl == tr)
        return tl;
    ll tm = (tl + tr) / 2;
    if (x <= t[p * 2])
        return query(p * 2, tl, tm, x);
    else
        return query(p * 2 + 1, tm + 1, tr, x - t[p * 2]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.assign(n + 1, 0);
    t.assign(4 * n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    build(1, 1, n);
    ll a = n;
    for (int i = n; i >= 1; i--)
    {
        ll z = abs(a - v[i]);
        a--;
        ll x = query(1, 1, n, z);
        update(1, 1, n, x);
        ans.pb(x);
    }
    reverse(all(ans));
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
