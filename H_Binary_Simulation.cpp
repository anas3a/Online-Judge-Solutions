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
        t[p] += 1;
        return;
    }
    int tm = (tl + tr) / 2;
    update(p * 2, tl, tm, l, min(r, tm));
    update(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int query(int p, int tl, int tr, int i)
{
    if (tl == tr)
        return t[p];
    int tm = (tl + tr) / 2;
    int tmp = 0;
    if (i <= tm)
        tmp = query(p * 2, tl, tm, i);
    else
        tmp = query(p * 2 + 1, tm + 1, tr, i);
    return t[p] + tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ts, cs = 0;
    cin >> ts;
    while (ts--)
    {
        cout << "Case " << ++cs << ":" << endl;
        cin >> s;
        t.clear();
        int n = sz(s);
        t.resize(4 * n + 1, 0);
        int q;
        cin >> q;
        while (q--)
        {
            char c;
            cin >> c;
            if (c == 'I')
            {
                int a, b;
                cin >> a >> b;
                update(1, 1, n, a, b);
            }
            else
            {
                int a;
                cin >> a;
                int x = query(1, 1, n, a);
                int ans = s[a - 1] - '0';
                if (x & 1)
                    ans = 1 - ans;
                cout << ans << '\n';
            }
        }
    }
    return 0;
}