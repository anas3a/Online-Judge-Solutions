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

pii p[1003][1003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vector<string> g(n);
    pii st, end;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'A')
                st = {i, j};
            if (g[i][j] == 'B')
                end = {i, j};
        }
    }
    p[st.ff][st.ss] = {-1, -1};
    queue<pii> q;
    q.push(st);
    g[st.ff][st.ss] = '#';
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};
    while (!q.empty())
    {
        if (q.front() == end)
            break;
        int x = q.front().ff, y = q.front().ss;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] != '#')
            {
                q.push({a, b});
                g[a][b] = '#';
                p[a][b] = {x, y};
            }
        }
    }
    if (g[end.ff][end.ss] != '#')
        cout << "NO" << endl;
    else
    {
        string ans;
        for (pii v = end; v != mp(-1, -1); v = p[v.ff][v.ss])
        {
            if (p[v.ff][v.ss] == mp(-1, -1))
                break;
            if (v.ff < p[v.ff][v.ss].ff)
                ans += 'U';
            else if (v.ff > p[v.ff][v.ss].ff)
                ans += 'D';
            else if (v.ss < p[v.ff][v.ss].ss)
                ans += 'L';
            else if (v.ss > p[v.ff][v.ss].ss)
                ans += 'R';
        }
        cout << "YES" << endl;
        reverse(all(ans));
        cout << sz(ans) << endl;
        cout << ans << endl;
    }
    return 0;
}
