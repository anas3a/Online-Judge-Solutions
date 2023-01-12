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

int bin_log[100005];
int v[100005][21];
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t, cs = 0;
    scanf("%d", &t);
    while (t--)
    {
        printf("Case %d:\n", ++cs);
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 2; i <= n; i++)
            bin_log[i] = bin_log[i / 2] + 1;
        int k = bin_log[n] + 1;
        for (int i = 0; i < n; i++)
            scanf("%d", &v[i][0]);
        for (int j = 1; j < k; j++)
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++)
            {
                v[i][j] = min(v[i][j - 1], v[i + (1 << (j - 1))][j - 1]);
            }
        }
        while(m--)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            a--;
            b--;
            int ln = bin_log[b - a + 1];
            int ans = min(v[a][ln], v[b - (1 << ln) + 1][ln]);
            printf("%d\n", ans);
        }
    }
    return 0;
}