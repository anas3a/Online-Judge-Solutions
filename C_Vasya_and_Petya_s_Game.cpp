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

    ll n;
    cin >> n;
    vvl v(n + 3);
    for (ll i = 2; i <= n; i++)
    {
        for (ll j = i + i; j <= n; j += i)
            v[j].pb(i);
    }
    vll ans;
    for (int i = 2; i <= n; i++)
    {
        if (sz(v[i]) <= 1)
            ans.pb(i);
        else
        {
            ll gcd = v[i][0];
            for (int j = 1; j < sz(v[i]); j++)
                gcd = __gcd(v[i][j], gcd);
            if (gcd != 1)
                ans.pb(i);
        }
    }
    cout << sz(ans) << endl;
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
