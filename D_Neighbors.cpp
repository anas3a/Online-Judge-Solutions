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
    bool flag = true;
    vvl v(n + 1);
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
        if (sz(v[a]) > 2 || sz(v[b]) > 2)
            flag = false;
    }
    if (!flag)
        cout << "No" << endl;
    else
    {
        queue<int> q;
        vector<bool> used(n + 1, false);
        vector<int> p(n + 1, -1);
        for (int i = 1; i <= n; i++)
        {
            if (!used[i])
            {
                q.push(i);
                used[i] = true;
                p[i] = -1;
                while (!q.empty())
                {
                    int x = q.front();
                    q.pop();
                    for (int u : v[x])
                    {
                        if (!used[u])
                        {
                            used[u] = true;
                            q.push(u);
                            p[u] = x;
                        }
                        else if (used[u] && u != p[x])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag)
                        break;
                }
            }
            if (!flag)
                break;
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}