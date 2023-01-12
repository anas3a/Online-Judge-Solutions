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

int v[1002][1002];
void update(int i, int j)
{
    while (i < 1002)
    {
        int j1 = j;
        while (j1 < 1002)
        {
            v[i][j1] += 1;
            j1 += (j1 & (-j1));
        }
        i += (i & -i);
    }
}

ll rsq(int i, int j)
{
    ll sum = 0;
    while (i > 0)
    {
        int j1 = j;
        while (j1 > 0)
        {
            sum += v[i][j1];
            j1 -= (j1 & (-j1));
        }
        i -= (i & -i);
    }
    return sum;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t, cs = 0;
    scanf("%d", &t);
    while (t--)
    {
        int q;
        scanf("%d", &q);
        vvi vis(1001, vi(1001, 0));
        memset(v, 0, sizeof(v));
        printf("Case %d:\n", ++cs);
        while (q--)
        {
            int a;
            cin >> a;
            if (!a)
            {
                int x, y;
                scanf("%d %d", &x, &y);
                if (vis[x][y])
                    continue;
                vis[x][y] = 1;
                x++, y++;
                update(x, y);
            }
            else
            {
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                int ans = 0;
                x1++, y1++, x2++, y2++;
                ans += rsq(x2, y2);
                ans -= rsq(x1 - 1, y2);
                ans -= rsq(x2, y1 - 1);
                ans += rsq(x1 - 1, y1 - 1);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}