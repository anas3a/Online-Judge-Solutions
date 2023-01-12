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

    ll h, n, ans = 0;
    cin >> h >> n;
    ll x = 1ll << h;
    ll f = 0, l = 1, r = x, level = h;
    while (level)
    {
        ll z = (r - l) / 2;
        if (n <= l + z)
        {
            if (!f)
                ans++;
            else
                ans += (1ll << level), f = 1 - f;
            r = l + z;
        }
        else
        {
            if (f)
                ans++;
            else
                ans += (1ll << level), f = 1 - f;;
            l = l + z + 1;
        }
        level--;
        f = 1 - f;
    }
    cout << ans << endl;
    return 0;
}
