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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, cs = 0;
    cin >> t;
    while (t--)
    {
        ll n, m, ans = 0;
        cin >> n >> m;
        vvi g(n + 1);
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        vi color(n + 1, -1);
        for (int i = 1; i <= n; i++)
        {
            set<ll> st;
            if (color[i] != -1)
                continue;
            color[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int u = q.front();
                st.insert(u);
                q.pop();
                for (auto &v : g[u])
                {
                    if (color[v] == -1)
                    {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if (color[v] == color[u])
                    {
                        break;
                    }
                }
            }
            ll c1 = 0, c0 = 0;
            for (int i = 1; i <= n; i++)
            {
                if (st.count(i))
                {
                    if (color[i])
                        c1++;
                    else
                        c0++;
                }
            }
            ans += max(c1, c0);
        }
        cout << "Case " << ++cs << ": ";
        cout << ans << endl;
    }
    return 0;
}