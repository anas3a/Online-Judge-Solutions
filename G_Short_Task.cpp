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

vll ans, sp;
vector<bool> p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    ll n = 1e7 + 5;
    ans.resize(n, 0);
    sp.resize(n, 0);
    p.resize(n, true);
    p[0] = p[1] = false;
    sp[1] = 1;
    for (ll i = 2; i < n; i++)
    {
        if (p[i])
        {
            sp[i] = i;
            for (ll j = i * i; j < n; j += i)
            {
                p[j] = false;
                if (sp[j] == 0)
                    sp[j] = i;
            }
        }
    }
    ans[1] = 1;
    for (ll i = 2; i < n; i++)
    {
        ll z = 1;
        ll x = i;
        ll xx = sp[x];
        ll yy = sp[x];
        while (true)
        {
            if (x == 1)
            {
                z *= (yy - 1) / (xx - 1);
                break;
            }
            if (xx == sp[x])
                yy *= sp[x];
            else
            {
                z *= (yy - 1) / (xx - 1);
                xx = sp[x];
                yy = xx * xx;
            }
            x /= sp[x];
        }
        if (z < n && ans[z] == 0)
            ans[z] = i;
    }
    while (t--)
    {
        ll c;
        cin >> c;
        if (ans[c] == 0)
            cout << "-1\n";
        else
            cout << ans[c] << "\n";
    }
    return 0;
}
