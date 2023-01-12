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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vvi v(n, vi(m));
        vpi ans;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                v[i][j] = (int)s[j] - '0';
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                ll cx = 0;
                vpi vx, vy;
                vy.pb({i, j});
                vy.pb({i, j + 1});
                vy.pb({i + 1, j});
                vy.pb({i + 1, j + 1});
                if (v[i][j])
                    vx.pb({i, j});
                if (v[i][j + 1])
                    vx.pb({i, j + 1});
                if (v[i + 1][j])
                    vx.pb({i + 1, j});
                if (v[i + 1][j + 1])
                    vx.pb({i + 1, j + 1});
                if (sz(vx) == 3)
                {
                    for (auto &i : vx)
                        ans.pb(i);
                }
                if (sz(vx) == 2)
                {
                    ans.pb(vx[0]);
                    for (int i = 0; i < sz(vy); i++)
                    {
                        if (find(all(vx), vy[i]) == vx.end())
                            ans.pb(vy[i]);
                    }
                    ans.pb(vx[1]);
                    for (int i = 0; i < sz(vy); i++)
                    {
                        if (find(all(vx), vy[i]) == vx.end())
                            ans.pb(vy[i]);
                    }
                }
                if (sz(vx) == 1)
                {
                    ans.pb(vx[0]);
                    vpi vz;
                    for (int i = 0; i < sz(vy); i++)
                    {
                        if (find(all(vx), vy[i]) == vx.end())
                            vz.pb(vy[i]);
                    }
                    ans.pb(vz[0]);
                    ans.pb(vz[1]);
                    ans.pb(vx[0]);
                    ans.pb(vz[1]);
                    ans.pb(vz[2]);
                    ans.pb(vx[0]);
                    ans.pb(vz[0]);
                    ans.pb(vz[2]);
                }
                if (sz(vx) == 4)
                {
                    ans.pb(vx[0]);
                    ans.pb(vx[1]);
                    ans.pb(vx[2]);
                    pii px = vx[3];
                    vx.clear();
                    vx.pb(px);
                    ans.pb(vx[0]);
                    vpi vz;
                    for (int i = 0; i < sz(vy); i++)
                    {
                        if (find(all(vx), vy[i]) == vx.end())
                            vz.pb(vy[i]);
                    }
                    ans.pb(vz[0]);
                    ans.pb(vz[1]);
                    ans.pb(vx[0]);
                    ans.pb(vz[1]);
                    ans.pb(vz[2]);
                    ans.pb(vx[0]);
                    ans.pb(vz[0]);
                    ans.pb(vz[2]);
                }
                v[i][j] = 0;
                v[i][j + 1] = 0;
                v[i + 1][j] = 0;
                v[i + 1][j + 1] = 0;
            }
        }
        cout << sz(ans) / 3 << endl;
        for (int i = 0; i < sz(ans); i++)
        {
            cout << ans[i].ff + 1 << " " << ans[i].ss + 1 << " ";
            if (i % 3 == 2)
                cout << endl;
        }
    }
    return 0;
}
