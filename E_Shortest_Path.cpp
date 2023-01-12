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

vvi g;
vi p;
vector<bool> vis;
set<pair<pii, int>> st;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    g.resize(n + 1);
    vis.resize(n + 1, false);
    p.resize(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        st.insert({{a, b}, c});
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            int a = -1, b, c;
            c = v, b = u;
            a = p[b];
            pair<pii, int> px = {{a, b}, c};
            if (!vis[v] && st.count(px) == 0)
            {
                vis[v] = true;
                q.push(v);
                p[v] = u;
            }
        }
    }
    if (!vis[n])
        cout << -1 << endl;
    else
    {
        vi ans;
        for (int i = n; i != -1; i = p[i])
            ans.pb(i);
        reverse(all(ans));
        cout << sz(ans) - 1 << endl;
        for (auto &i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
