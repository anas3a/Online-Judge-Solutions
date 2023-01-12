#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
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

vector<bool> v(20000001, true);
vpi ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n = 20000000;
    v[0] = v[1] = false;
    ans.pb(mp(0, 0));
    for (ll i = 2; i * i <= n; i++)
    {
        if (v[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                v[j] = false;
            }
        }
    }
    for (ll i = 5; i <= n; i += 2)
    {
        if (v[i] && v[i - 2])
        ans.pb(mp(i - 2, i));
    }
    int s;
    while (cin >> s)
    {
        cout << "(" << ans[s].ff << ", " << ans[s].ss << ")" << endl;
    }
    return 0;
}
