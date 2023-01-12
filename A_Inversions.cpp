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
int query(int p, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[p];
    int tm = (tl + tr) / 2;
    return query(p * 2, tl, tm, l, min(r, tm)) +
           query(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void update(int p, int tl, int tr, int i)
{
    if (tl == tr)
    {
        t[p] = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    if (i <= tm)
        update(p * 2, tl, tm, i);
    else
        update(p * 2 + 1, tm + 1, tr, i);
    t[p] = t[p * 2] + t[p * 2 + 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    t.assign(4 * n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cout << query(1, 1, n, x + 1, n) << " ";
        update(1, 1, n, x);
    }
    cout << endl;
    return 0;
}
