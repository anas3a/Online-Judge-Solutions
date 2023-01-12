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
    vpl v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].ff, v[i].ss = i;
    vvl vx(m, vll(3));
    for (int i = 0; i < m; i++)
        cin >> vx[i][0];
    for (int i = 0; i < m; i++)
        cin >> vx[i][1], vx[i][2] = i;
    sort(all(vx));
    sort(rall(v));
    bool flag = false;
    vi ans(n);
    vector <bool> vis(m, false);
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < m && vx[j][0] < v[i].ff)
            j++;
        if (j == m)
        {
            flag = true;
            break;
        }
        ll mn = INT_MAX, ind = -1;
        while (j < m)
        {
            if (vx[j][1] < mn && !vis[vx[j][2]])
            {
                mn = vx[j][1];
                ind = j;
            }
            j++;
        }
        if (ind == -1)
        {
            flag = true;
            break;
        }
        ans[v[i].ss] = vx[ind][2] + 1;
        vis[vx[ind][2]] = true;
    }
    if (flag)
        cout << "impossible" << endl;
    else
    {
        for (int i = 0; i < sz(ans); i++)
        {
            if (i)
                cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}