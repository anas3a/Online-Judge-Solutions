// Maximum flow - Edmonds-Karp - O(VE^2)

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

// ll n;
// vector<vector<ll>> capacity;
// vector<vector<ll>> adj;

// ll bfs(ll s, ll t, vector<ll> &parent)
// {
//     fill(parent.begin(), parent.end(), -1);
//     parent[s] = -2;
//     queue<pair<ll, ll>> q;
//     q.push({s, LLONG_MAX});
//     while (!q.empty())
//     {
//         ll cur = q.front().first;
//         ll flow = q.front().second;
//         q.pop();
//         for (ll next : adj[cur])
//         {
//             if (parent[next] == -1 && capacity[cur][next])
//             {
//                 parent[next] = cur;
//                 ll new_flow = min(flow, capacity[cur][next]);
//                 if (next == t)
//                     return new_flow;
//                 q.push({next, new_flow});
//             }
//         }
//     }
//     return 0;
// }

// ll EdmondKarp(ll s, ll t)
// {
//     ll flow = 0;
//     vector<ll> parent(n);
//     ll new_flow;
//     while (new_flow = bfs(s, t, parent))
//     {
//         flow += new_flow;
//         ll cur = t;
//         while (cur != s)
//         {
//             ll prev = parent[cur];
//             capacity[prev][cur] -= new_flow;
//             capacity[cur][prev] += new_flow;
//             cur = prev;
//         }
//     }
//     return flow;
// }

struct FlowEdge
{
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};
struct Dinic
{
    const long long flow_inf = LLONG_MAX;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
    Dinic(int n, int s, int t) : n(n), s(s), t(t)
    {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void add_edge(int v, int u, long long cap)
    {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }
    bool bfs()
    {
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int id : adj[v])
            {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }
    long long dfs(int v, long long pushed)
    {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int &cid = ptr[v]; cid < (int)adj[v].size(); cid++)
        {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
    long long flow()
    {
        long long f = 0;
        while (true)
        {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf))
            {
                f += pushed;
            }
        }
        return f;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    Dinic dinic(n, 0, n - 1);
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        dinic.add_edge(a, b, c);
    }
    cout << dinic.flow() << nl;
    return 0;
}