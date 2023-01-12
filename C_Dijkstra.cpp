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

vector<vector<pair<long, long>>> adj;
vector<long long> d, p;
void dijkstra(int s)
{
    int n = adj.size();
    d.clear();
    p.clear();
    d.assign(n, LLONG_MAX);
    p.assign(n, -1);
    d[s] = 0;
    priority_queue<pll, vpl, greater<pll>> q;
    q.push({0, s});
    while (!q.empty())
    {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;
        for (auto &edge : adj[v])
        {
            ll to = edge.first;
            ll len = edge.second;
            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    adj.resize(n);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    dijkstra(0);
    if (d[n - 1] == LLONG_MAX)
        cout << -1 << endl;
    else
    {
        vi ans;
        for (int i = n - 1; i != -1; i = p[i])
            ans.pb(i);
        reverse(all(ans));
        for (auto &i : ans)
            cout << i + 1 << " ";
        cout << endl;
    }
    return 0;
}