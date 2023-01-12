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
        ll n, k;
        cin >> n >> k;
        vll vk(k);
        vvl g(n + 1);
        for (auto &i : vk)
            cin >> i;
        for (int i = 0; i < n - 1; i++)
        {
            ll a, b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }

        ll s = 1;
        queue<int> q;
        vector<bool> used(n + 1, false);
        vector<int> p(n + 1, -1);
        for (int i = 0; i < k; i++)
        {
            q.push(vk[i]);
            p[vk[i]] = vk[i];
            used[vk[i]] = true;
        }
        q.push(s);
        used[s] = true;
        p[s] = s;
        set<ll> st;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int u : g[v])
            {
                if (!used[u])
                {
                    used[u] = true;
                    q.push(u);
                    p[u] = p[v];
                }
                if (used[u] && (p[u] == 1 || p[v] == 1))
                {
                    if (p[u] != p[v])
                    {
                        if (p[u] == 1)
                            st.insert(p[v]);
                        else
                            st.insert(p[u]);
                    }
                }
            }
        }
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            if (sz(g[i]) == 1 && i != s && p[i] == s)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << -1 << endl;
        else
            cout << sz(st) << endl;
    }
    return 0;
}