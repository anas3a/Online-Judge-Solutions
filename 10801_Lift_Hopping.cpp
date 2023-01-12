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

    ll n, k;
    while (cin >> n >> k)
    {
        vll time(n);
        for (auto &i : time)
            cin >> i;
        vvl floor(n);
        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            string s;
            getline(cin, s);
            stringstream ss(s);
            ll u;
            while (ss >> u)
                floor[i].pb(u);
        }
        vvl graph[100];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < sz(floor[i]); j++)
            {
                for (int l = 0; l < sz(floor[i]); l++)
                {
                    if (j == l)
                        continue;
                    vll tmp(3);
                    tmp[1] = floor[i][l];
                    tmp[0] = time[i] * abs(floor[i][l] - floor[i][j]);
                    tmp[2] = i;
                    graph[floor[i][j]].push_back(tmp);
                }
            }
        }
        priority_queue<vll, vector<vll>, greater<vll>> q;
        vll d(100, 1e15);
        d[0] = 0;
        for (int i = 0; i < n; i++)
        {
            if (floor[i][0] == 0)
            {
                vll tmp(3);
                tmp[0] = 0;
                tmp[1] = 0;
                tmp[2] = i;
                q.push(tmp);
            }
        }
        while (!q.empty())
        {
            ll u = q.top()[1], du = q.top()[0], cur = q.top()[2];
            q.pop();
            if (du > d[u])
                continue;
            for (auto &v : graph[u])
            {
                ll cst = d[u] + v[0];
                if (cur != v[2])
                    cst += 60;
                if (cst < d[v[1]])
                {
                    d[v[1]] = cst;
                    vll tmp(3);
                    tmp[0] = cst;
                    tmp[1] = v[1];
                    tmp[2] = v[2];
                    q.push(tmp);
                }
            }
        }
        if (d[k] == 1e15)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << d[k] << endl;
    }
    return 0;
}
