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

    ll n, m;
    cin >> n >> m;
    vector<vpl> g(n + 1);
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b, c});
    }
    vll d(n + 1, 1e15);
    priority_queue<pll, vpl, greater<pll>> q;
    q.push({0, 1});
    d[1] = 0;
    while (!q.empty())
    {
        int u = q.top().ss, du = q.top().ff;
        q.pop();
        if (du > d[u])
            continue;
        for (auto &v : g[u])
        {
            if (d[u] + v.ss < d[v.ff])
            {
                d[v.ff] = d[u] + v.ss;
                q.push({d[v.ff], v.ff});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
    cout << endl;
    return 0;
}
