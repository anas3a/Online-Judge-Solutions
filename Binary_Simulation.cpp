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

vll t;
string s;
void update(int p, int tl, int tr, int l, int r)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[p]++;
        return;
    }
    int tm = (tl + tr) / 2;
    update(p * 2, tl, tm, l, min(r, tm));
    update(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

ll query(int p, int tl, int tr, int i)
{
    if (tl == tr)
        return t[p];
    int tm = (tl + tr) / 2;
    ll tmp = 0;
    if (i <= tm)
        tmp = query(p * 2, tl, tm, i);
    else
        tmp = query(p * 2 + 1, tm + 1, tr, i);
    return tmp + t[p];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ts, cs = 0;
    cin >> ts;
    while (ts--)
    {
        ll q, n;
        string st;
        cin >> st >> q;
        s = "x" + st;
        n = sz(s);
        t.assign(4 * n + 1, 0);
        cout << "Case " << ++cs << ": " << endl;
        while (q--)
        {
            string sx;
            cin >> sx;
            if (sx == "I")
            {
                ll a, b;
                cin >> a >> b;
                update(1, 1, n, a, b);
            }
            else
            {
                ll a;
                cin >> a;
                ll x = query(1, 1, n, a);
                if (x & 1)
                    cout << '1' - s[a] << endl;
                else
                    cout << s[a] << endl;
            }
        }
    }
    return 0;
}