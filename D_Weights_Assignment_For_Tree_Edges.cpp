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
        ll n;
        cin >> n;
        vll b(n), p(n);
        map<ll, vll> mp;
        ll root;
        for (int i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            b[i] = a - 1;
            if (i == a - 1)
                root = i;
            else
                mp[a - 1].pb(i);
        }
        for (int i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            p[a - 1] = i;
        }
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (p[i] < p[b[i]])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            cout << -1 << endl;
        else
        {
            vll ans(n, 0);
            vll sum(n, 0);
            queue<ll> q;
            q.push(root);
            while (!q.empty())
            {
                ll u = q.front();
                q.pop();
                for (auto &i : mp[u])
                {
                    q.push(i);
                    ans[i] = p[i] - sum[u];
                    sum[i] = ans[i] + sum[u];
                }
            }
            for (auto &i : ans)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}