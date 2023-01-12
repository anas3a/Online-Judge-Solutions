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
        ll ans = 0, sum = 0, n;
        cin >> n;
        for (int i = 0; i < n - 1; i++)
        {
            ll a, b;
            cin >> a >> b;
            sum += a;
            sum -= b;
            ans = max(ans, sum);
        }
        cout << "Case " << ++cs << ": " << ans << endl;
    }
    return 0;
}