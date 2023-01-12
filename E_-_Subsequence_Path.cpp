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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<pair<int, int>, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({{b, c}, i});
    }

    vvi adjx(m + 1);
    for (int i = 0; i < k; i++)
    {
        ll a;
        cin >> a;
        adjx[a - 1].pb(i);
    }

    for (auto &i : adjx)
    {
        sort(all(i));
    }

    queue<pair<pll, ll>> q;
    q.push({{1, -1}, 0});
    ll ans = LLONG_MAX;
    while (!q.empty())
    {
        int u = q.front().ff.ff;
        int prev_pos = q.front().ff.ss;
        ll costx = q.front().ss;
        q.pop();
        for (auto &i : adj[u])
        {
            int ind = i.ss;
            auto it = upper_bound(all(adjx[ind]), prev_pos);
            if (it == adjx[ind].end())
                continue;
            ll costt = costx + i.ff.ss;
            int j = it - adjx[ind].begin();
            q.push({{i.ff.ff, adjx[ind][j]}, costt});
            if (i.ff.ff == n)
                ans = min(ans, costt);
            // for (int j = it - adjx[ind].begin(); j < sz(adjx[ind]); j++)
            // {
            //     ll costt = costx + i.ff.ss;
            //     q.push({{i.ff.ff, adjx[ind][j]}, costt});
            //     if (i.ff.ff == n)
            //         ans = min(ans, costt);
            // }
        }
    }
    if (ans == LLONG_MAX)
        ans = -1;
    cout << ans << nl;
    return 0;
}