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
void push(int p, int tl, int tr)
{
    if (tl == tr)
        return;
    if (t[p] != -1)
    {
        t[p * 2] = t[p];
        t[p * 2 + 1] = t[p];
        t[p] = -1;
    }
}
void update(int p, int tl, int tr, int l, int r, int x)
{
    push(p, tl, tr);
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[p] = x;
        return;
    }
    int tm = (tl + tr) / 2;
    update(p * 2, tl, tm, l, min(r, tm), x);
    update(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
}
int query(int p, int tl, int tr, int x)
{
    push(p, tl, tr);
    if (tl == tr)
        return t[p];
    int tm = (tl + tr) / 2;
    if (x <= tm)
        return query(p * 2, tl, tm, x);
    else
        return query(p * 2 + 1, tm + 1, tr, x);
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int ty, cs = 0;
    scanf("%d", &ty);
    while (ty--)
    {
        int nx;
        scanf("%d", &nx);
        int n = 2 * nx, cnt = 0;
        t.clear();
        t.resize(4 * n, 0);
        printf("Case %d: ", ++cs);
        int lx = INT_MAX, rx = INT_MIN;
        while (nx--)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            lx = min(l, lx);
            rx = max(rx, r);
            update(1, 1, n, l, r, ++cnt);
        }
        set<int> st;
        for (int i = lx; i <= rx; i++)
        {
            int x = query(1, 1, n, i);
            if (x)
                st.insert(x);
        }
        printf("%d\n", sz(st));
    }
    return 0;
}