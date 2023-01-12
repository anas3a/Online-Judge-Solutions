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

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        vpi w, b;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == '1')
                    w.pb({i, j});
                else
                    b.pb({i, j});
            }
        }
        vvi vx(n, vi(m, INT_MAX));
        for (auto &i : w)
        {
            vx[i.ff][i.ss] = 0;
            for (auto &j : b)
            {
                if (abs(i.ff - j.ff) + abs(i.ss - j.ss) < vx[j.ff][j.ss])
                    vx[j.ff][j.ss] = abs(i.ff - j.ff) + abs(i.ss - j.ss);
            }
        }
        for (auto &i : vx)
        {
            for (auto &j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
