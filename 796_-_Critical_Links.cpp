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

int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin, low;
int timer;
vector<pair<int, int>> is_bridge;
vector<int> is_articulation_point;

void dfs(int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : adj[v])
    {
        if (to == p)
            continue;
        if (visited[to])
            low[v] = min(low[v], tin[to]);
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                is_bridge.push_back({v, to});
            if (low[to] >= tin[v] && p != -1)
                is_articulation_point.push_back(v);
            ++children;
        }
    }
    if (p == -1 && children > 1)
        is_articulation_point.push_back(v);
}

void find_articulationPoint_Bridge()
{
    timer = 0;
    visited.clear();
    tin.clear();
    low.clear();
    is_bridge.clear();
    is_articulation_point.clear();
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n)
    {
        adj.clear();
        adj.resize(n);
        for (int i = 0; i < n; i++)
        {
            char c;
            int a, j;
            cin >> a >> c >> j >> c;
            cin.ignore();
            while (j--)
            {
                int b;
                cin >> b;
                adj[a].pb(b);
            }
        }
        find_articulationPoint_Bridge();
        cout << sz(is_bridge) << " critical links" << nl;
        sort(all(is_bridge));
        for (auto &i : is_bridge)
        {
            cout << i.ff << " - " << i.ss << nl;
        }
        cout << nl;
    }
    return 0;
}