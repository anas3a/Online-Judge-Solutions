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

vi v;
void update(int i, int val)
{
    while (i < sz(v))
    {
        v[i] += val;
        i += (i & (-i));
    }
}

ll rsq(int i)
{
    ll sum = 0;
    while (i > 0)
    {
        sum += v[i];
        i -= (i & (-i));
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
        printf("Case %d:\n", ++cs);
        int n, q;
        scanf("%d %d", &n, &q);
        v.clear();
        v.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int a;
            scanf("%d", &a);
            v[i] += a;
            if (i + (i & (-i)) <= n)
                v[i + (i & (-i))] += v[i];
        }
        while (q--)
        {
            int a;
            scanf("%d", &a);
            if (a == 1)
            {
                int u;
                scanf("%d", &u);
                u++;
                ll x = rsq(u) - rsq(u - 1);
                update(u, -x);
                printf("%lld\n", x);
            }
            else if (a == 2)
            {
                int u, v;
                scanf("%d %d", &u, &v);
                u++;
                update(u, v);
            }
            else
            {
                int u, v;
                scanf("%d %d", &u, &v);
                v++;
                ll x = rsq(v) - rsq(u);
                printf("%lld\n", x);
            }
        }
    }
    return 0;
}