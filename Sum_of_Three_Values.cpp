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

    ll n, x;
    cin >> n >> x;
    vll v(n);
    map<ll, vi> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]].pb(i);
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > x - 2)
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] + v[j] > x - 1)
                continue;
            ll z = x - v[i] - v[j];
            if (m.find(z) != m.end())
            {
                for (auto &k : m[z])
                {
                    if (k != i && k != j)
                    {
                        cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
