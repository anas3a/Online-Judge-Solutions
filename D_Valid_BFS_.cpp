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

vi pos;
bool comp(int &a, int &b)
{
    return pos[a] < pos[b];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vvi g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    pos.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pos[x] = i;
    }
    for (int i = 1; i <= n; i++)
        sort(all(g[i]), comp);
    vi lev(n + 1, INT_MAX);
    queue<int> q;
    q.push(1);
    lev[1] = 0;
    int z = 0;
    bool f = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (z != pos[x])
        {
            f = false;
            break;
        }
        z++;
        for (auto &i : g[x])
        {
            if (lev[i] == INT_MAX)
            {
                lev[i] = lev[x] + 1;
                q.push(i);
            }
        }
    }
    if (f)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
