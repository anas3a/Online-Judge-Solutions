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

    ll n;
    cin >> n;
    vll v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<vpl> vx(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (v[j] <= v[i])
            {
                vx[i].pb({v[j], j});
            }
        }
    }
    set<pll> st;
    vll ans;
    ans.pb(0);
    vll vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (v[i] > i)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if (vis[j])
                continue;
            if (v[j] > sz(ans))
                continue;
            bool flag = true;
            for (int k = 0; k < sz(vx[j]); k++)
            {
                if (!st.count(vx[j][k]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                st.insert({v[j], j});
                vis[j] = true;
                ans.pb(v[j]);
                break;
            }
        }
    }
    for (int i = 1; i < sz(ans); i++)
        cout << ans[i] << nl;
    return 0;
}