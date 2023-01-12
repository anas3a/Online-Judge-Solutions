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

vll parent, sizex;
void make_set(int v)
{
    parent[v] = v;
    sizex[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sizex[a] < sizex[b])
            swap(a, b);
        parent[b] = a;
        sizex[a] += sizex[b];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vvl g(n + 1);
    parent.resize(n + 1);
    sizex.resize(n + 1);
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    vll ans;
    for (int i = 1; i <= n; i++)
        make_set(i);
    ll cnt = 0;
    ans.pb(0);
    for (int i = n; i >= 2; i--)
    {
        cnt++;
        for (auto &j : g[i])
        {
            if (j > i && find_set(i) != find_set(j))
            {
                union_sets(i, j);
                cnt--;
            }
        }
        ans.pb(cnt);
    }
    reverse(all(ans));
    for (auto &i : ans)
        cout << i << endl;
    return 0;
}