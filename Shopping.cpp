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

ll dx[4] = {0, 0, -1, 1};
ll dy[4] = {1, -1, 0, 0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        int n, m;
        cin >> m >> n;
        if (m + n == 0)
            break;
        vector<string> v(n);
        for (auto &i : v)
            cin >> i;
        pll st, end;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == 'S')
                    st = {i, j};
                if (v[i][j] == 'D')
                    end = {i, j};
            }
        }
        vvl d(n, vll(m, 1e15));
        priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
        d[st.ff][st.ss] = 0;
        pq.push({0, {st.ff, st.ss}});
        while (!pq.empty())
        {
            pll u = pq.top().ss;
            ll du = pq.top().ff;
            pq.pop();
            if (du > d[u.ff][u.ss] || u == end)
                continue;
            for (int i = 0; i < 4; i++)
            {
                ll x = u.ff + dx[i];
                ll y = u.ss + dy[i];
                if (x >= 0 && y >= 0 && x < n && y < m && v[x][y] != 'X')
                {
                    ll cst = v[x][y] - '0';
                    if (v[x][y] == 'D')
                        cst = 0;
                    if (d[u.ff][u.ss] + cst < d[x][y])
                    {
                        d[x][y] = d[u.ff][u.ss] + cst;
                        pq.push({d[x][y], {x, y}});
                    }
                }
            }
        }
        cout << d[end.ff][end.ss] << endl;
    }
    return 0;
}
