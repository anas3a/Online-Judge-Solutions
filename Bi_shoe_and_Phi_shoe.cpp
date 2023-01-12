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

    ll mx = 1e6 + 3;
    vll phi(mx + 3);

    for (int i = 0; i <= mx; i++)
        phi[i] = i;

    for (int i = 2; i <= mx; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= mx; j += i)
                phi[j] -= phi[j] / i;
        }
    }

    ll t, cs = 0;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            if (a == 1)
            {
                ans += 2;
                continue;
            }
            for (int j = a;; j++)
            {
                if (phi[j] >= a)
                {
                    ans += j;
                    break;
                }
            }
        }
        cout << "Case " << ++cs << ": " << ans << " Xukha" << endl;
    }
    return 0;
}