#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpi = vector<pii>;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define dg(x) cout << #x << " = " << x << endl

ll n, m;
vector<bool> visited;
vi color, path;

void dfs(int u)
{
    bool fx = true;
    visited[u] = true;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && i != u && color[i] != color[u])
        {
            fx = false;
            path[i] = u;
            dfs(i);
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        visited.clear();
        visited.resize(n + 1, false);
        color.clear();
        color.resize(n + 1);
        path.clear();
        path.resize(n + 1, -1);
        for (int i = 1; i <= n; i++)
        {
            cin >> color[i];
        }
        dfs(1);
        bool f = true;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                cout << "NO" << endl;
                f = false;
                break;
            }
        }
        if (f)
        {
            cout << "YES" << endl;
            for (int i = 2; i <= n; i++)
            {
                cout << i << " " << path[i] << endl; 
            }
        }
    }
    return 0;
}
