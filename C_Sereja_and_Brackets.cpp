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
    int lb = 0, rb = 0, cnt = 0;
};
string s;
vector<dt> t;
dt z;
dt mrg(const dt &a, const dt &b)
{
    dt c;
    c.cnt = a.cnt + b.cnt;
    c.cnt += min(a.lb, b.rb);
    c.lb = a.lb + b.lb - min(a.lb, b.rb);
    c.rb = a.rb + b.rb - min(a.lb, b.rb);
    return c;
}
void build(int p, int tl, int tr)
{
    if (tl == tr)
    {
        if (s[tl] == '(')
            t[p].lb = 1;
        else
            t[p].rb = 1;
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

    s = "x";
    string z;
    cin >> z;
    s += z;
    int n = sz(s);
    t.resize(4 * (n + 1));
    build(1, 1, n);
    int m;
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l, r).cnt * 2 << '\n';
    }
    return 0;
}
