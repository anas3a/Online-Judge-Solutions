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

vi p, sz;
int get(int u)
{
    if (u == p[u])
        return u;
    return p[u] = get(p[u]);
}
void uni(int u, int v)
{
    u = get(u);
    v = get(v);
    if (u != v)
    {
        if (sz[u] < sz[v])
            swap(u, v);
        p[v] = u;
        sz[u] += sz[v];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    p.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    while (m--)
    {
        string s;
        int u, v;
        cin >> s >> u >> v;
        if (s == "union")
            uni(u, v);
        else
        {
            if (get(u) == get(v))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
