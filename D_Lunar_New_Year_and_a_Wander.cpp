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

    ll n, m;
    cin >> n >> m;
    vvl v(n + 1);
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    vector<bool> vis(n + 1, false);
    vll ans;
    priority_queue<ll, vll, greater<ll>> pq;
    pq.push(1);
    vis[1] = true;
    while (!pq.empty())
    {
        ll u = pq.top();
        pq.pop();
        for (auto &i : v[u])
        {
            if (!vis[i])
            {
                vis[i] = true;
                pq.push(i);
            }
        }
        ans.pb(u);
    }
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
