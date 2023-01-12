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
set<pair<int, int>> is_bridge;
set<int> is_articulation_point;

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
                is_bridge.insert({v, to});
            if (low[to] >= tin[v] && p != -1)
                is_articulation_point.insert(v);
            ++children;
        }
    }
    if (p == -1 && children > 1)
        is_articulation_point.insert(v);
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

    while (true)
    {
        cin >> n;
        cin.ignore();
        if (!n)
            break;
        adj.clear();
        adj.resize(n);
        string s;
        while (getline(cin, s))
        {
            if (s == "0")
                break;
            stringstream ss(s);
            int a, b;
            ss >> a;
            a--;
            while (ss >> b)
            {
                b--;
                adj[a].pb(b);
                adj[b].pb(a);
            }
        }
        find_articulationPoint_Bridge();
        cout << sz(is_articulation_point) << nl;
    }
    return 0;
}