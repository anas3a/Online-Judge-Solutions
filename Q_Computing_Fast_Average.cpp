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

vll t, tx;
void push(int p, int tl, int tr)
{
    if (tl == tr)
        return;
    if (tx[p] != -1)
    {
        int tm = (tl + tr) / 2;
        t[p * 2] = (tm - tl + 1) * tx[p];
        t[p * 2 + 1] = (tr - tm) * tx[p];
        tx[p * 2] = tx[p];
        tx[p * 2 + 1] = tx[p];
        tx[p] = -1;
    }
}
void update(int p, int tl, int tr, int l, int r, int x)
{
    push(p, tl, tr);
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[p] = x * (tr - tl + 1);
        tx[p] = x;
        return;
    }
    int tm = (tl + tr) / 2;
    update(p * 2, tl, tm, l, min(r, tm), x);
    update(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    t[p] = t[p * 2] + t[p * 2 + 1];
}
ll query(int p, int tl, int tr, int l, int r)
{
    push(p, tl, tr);
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[p];
    int tm = (tl + tr) / 2;
    return query(p * 2, tl, tm, l, min(r, tm)) +
           query(p * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int ty, cs = 0;
    scanf("%d", &ty);
    while (ty--)
    {
        printf("Case %d:\n", ++cs);
        int n, q;
        scanf("%d %d", &n, &q);
        t.clear();
        t.resize(4 * n + 1, 0);
        tx.clear();
        tx.resize(4 * n + 1, -1);
        while (q--)
        {
            int a;
            scanf("%d", &a);
            if (a == 1)
            {
                int b, c, x;
                scanf("%d %d %d", &b, &c, &x);
                update(1, 1, n, b + 1, c + 1, x);
            }
            else
            {
                int b, c;
                scanf("%d %d", &b, &c);
                int sum = query(1, 1, n, b + 1, c + 1);
                int ind = c - b + 1;
                if (sum % ind == 0)
                    printf("%d\n", sum / ind);
                else 
                {
                    int x = __gcd(sum, ind);
                    sum /= x;
                    ind /= x;
                    printf("%d/%d\n", sum, ind);
                }
            }
        }
    }
    return 0;
}