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
struct dt
{
    string s;
    int u, v;
};
vector<dt> v;
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

    int n, m, k;
    cin >> n >> m >> k;
    p.resize(n + 1);
    sz.resize(n + 1, 1);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
    }
    v.resize(k);
    for (auto &i : v)
        cin >> i.s >> i.u >> i.v;
    reverse(all(v));
    vector<string> ans;
    for (auto &i : v)
    {
        if (i.s == "cut")
            uni(i.u, i.v);
        else
        {
            if (get(i.u) == get(i.v))
                ans.pb("YES");
            else
                ans.pb("NO");
        }
    }
    reverse(all(ans));
    for (auto &i : ans)
        cout << i << endl;
    return 0;
}
