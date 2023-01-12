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

    ll a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << endl;
        return 0;
    }
    vi v = {2, 3, 5};
    vll vx(10, 0), vy(10, 0);
    ll ans = 0;
    for (int i = 0; i < 3; i++)
    {
        while (a % v[i] == 0)
        {
            a /= v[i];
            vx[v[i]]++;
        }
        while (b % v[i] == 0)
        {
            b /= v[i];
            vy[v[i]]++;
        }
        ans += abs(vx[v[i]] - vy[v[i]]);
    }
    if (a != b)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
