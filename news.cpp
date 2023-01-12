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
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;
    vvi g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    vi v;
    v.pb(a);
    v.pb(b);
    int x = 0;
    vi lev(n + 3, -1);
    lev[a] = lev[b] = x;
    while (true)
    {
        x++;
        vi temp;
        for (auto &i : v)
        {
            for (auto &j : g[i])
            {
                if (lev[j] == -1)
                {
                    lev[j] = x;
                    temp.pb(j);
                    break;
                }
            }
        }
        v.insert(v.end(), all(temp));
        if (sz(v) == n)
            break;
    }
    int ans = -1;
    for (int i = 0; i <= n; i++)
        ans = max(ans, lev[i]);
    cout << ans << endl;
    return 0;
}