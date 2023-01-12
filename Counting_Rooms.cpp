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

ll n, m;
vector<string> g;

void dfs(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || g[i][j] == '#')
        return;
    g[i][j] = '#';
    dfs(i, j + 1);
    dfs(i, j - 1);
    dfs(i - 1, j);
    dfs(i + 1, j);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n);
    for (auto &i : g)
        cin >> i;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '.')
            {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
