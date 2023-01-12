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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vi vx(n + 1);
    vvi v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> vx[i];
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    map<int, set<int>> vs;
    int mx = 0, ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        vs[vx[i]].insert(vx[i]);
        for (int j = 0; j < sz(v[i]); j++)
            vs[vx[i]].insert(vx[v[i][j]]);
    }
    for (auto &i : vs)
    {
        if (sz(i.ss) == mx)
            ans = min(ans, i.ff);
        if (sz(i.ss) > mx)
        {
            mx = sz(i.ss);
            ans = i.ff;
        }
    }
    cout << ans << endl;
    return 0;
}
