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

bool comp(vi a, vi b)
{
    return sz(a) > sz(b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vvi v(n);
        for (int i = 0; i < n; i++)
        {
            int nx;
            cin >> nx;
            for (int j = 0; j < nx; j++)
            {
                int a;
                cin >> a;
                v[i].pb(a);
            }
        }
        sort(all(v), comp);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            vector<bool> vis(k + 1, false);
            int cnt = 0;
            for (int j = 0; j < sz(v[i]); j++)
            {
                vis[v[i][j]] = true;
            }
            for (int j = i + 1; j < n; j++)
            {
                cnt = sz(v[i]);
                for (int k = 0; k < sz(v[j]); k++)
                {
                    if (!vis[v[j][k]])
                        cnt++;
                }
                if (cnt == k)
                    ans++;
            }
        }
        cout << ans << nl;
    }
    return 0;
}