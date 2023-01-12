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

    ll t, cs = 0;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll v(n + 1), pos(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            pos[v[i]] = i;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == i)
                continue;
            ans++;
            ll tmp = pos[i];
            pos[v[i]] = pos[i];
            pos[i] = i;
            v[tmp] = v[i];
            v[i] = i;
        }
        cout << "Case " << ++cs << ": " << ans << endl;
    }
    return 0;
}