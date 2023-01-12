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

ll n, k;
vll v, vb, vc;
ll dp[1003][3003];
ll f(int i, int kx)
{
    if (i == n)
        return 0;
    if (dp[i][kx] != -1)
        return dp[i][kx];
    ll a = f(i + 1, kx), b = 0;
    if (v[i] + kx <= k)
        b = vc[i] + f(i + 1, kx + v[i]);
    return dp[i][kx] = max(a, b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        v.clear();
        v.resize(n);
        vb.clear();
        vb.resize(n);
        vc.clear();
        vc.resize(n);
        for (auto &i : vb)
            cin >> i;
        for (auto &i : vc)
            cin >> i;
        for (int i = 0; i < n; i++)
        {
            ll x = 1, kc = 0, c = 1;
            while (x != vb[i])
            {
                while (x / c > vb[i] - x)
                    c++;
                x += x / c;
                kc++;
            }
            v[i] = kc;
        }
        for (auto &i : v)
            cout << i << " ";
        cout << endl;
        memset(dp, -1, sizeof(dp));
        cout << f(0, 0) << endl;
    }
    return 0;
}