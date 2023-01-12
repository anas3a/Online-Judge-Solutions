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

vll v;
ll dp[10003];
ll lis(ll i)
{
    if (dp[i] != -1)
        return dp[i];
    ll ans = 0;
    for (int j = i + 1; j < sz(v); j++)
    {
        if (v[j] <= v[i])
            ans = max(ans, lis(j));
    }
    return dp[i] = ans + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll tc = 0;
    while (true)
    {
        v.clear();
        memset(dp, -1, sizeof(dp));
        while (true)
        {
            ll a;
            cin >> a;
            if (a == -1)
                break;
            v.pb(a);
        }
        if (!sz(v))
            break;
        ll z = 0;
        for (int i = 0; i < sz(v); i++)
            z = max(z, lis(i));
        if (tc)
            cout << endl;
        cout << "Test #" << ++tc << ":\n";
        cout << "  maximum possible interceptions: " << z << '\n';
    }
    return 0;
}
