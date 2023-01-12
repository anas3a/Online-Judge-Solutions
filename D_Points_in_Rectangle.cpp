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
        vi vx[1001];
        vvi vis(1001, vi(1001, 0));
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
                vx[x].pb(y);
            }
            else
            {
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                int ans = 0;
                for (int i = x1; i <= x2; i++)
                {
                    int ind1 = lower_bound(all(vx[i]), y1) - vx[i].begin();
                    int ind2 = upper_bound(all(vx[i]), y2) - vx[i].begin();
                    ans += ind2 - ind1;
                }
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}