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

vi p, sz, xp;
int get(int u)
{
    if (u == p[u])
        return u;
    return get(p[u]);
}
ll get_xp(int u)
{
    if (u == p[u])
        return xp[u];
    return xp[u] + get_xp(p[u]);
}
void uni(int a, int b)
{
    a = get(a);
    b = get(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        p[b] = a;
        sz[a] += b;
        xp[b] -= xp[a];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    p.resize(n + 1);
    sz.resize(n + 1, 1);
    xp.resize(n + 1);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    while (m--)
    {
        string s;
        cin >> s;
        if (s == "join")
        {
            int x, y;
            cin >> x >> y;
            uni(x, y);
        }
        else if (s == "add")
        {
            int x, v;
            cin >> x >> v;
            int u = get(x);
            xp[u] += v;
        }
        else
        {
            int x;
            cin >> x;
            cout << get_xp(x) << endl;
        }
    }
    return 0;
}
