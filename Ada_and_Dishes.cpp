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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vi v(n);
        for (auto &i : v)
            cin >> i;
        ll ans = 1e5;
        for (int i = 0; i < (1 << n); i++)
        {
            ll sum1 = 0, sum2 = 0;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    sum1 += v[j];
                else
                    sum2 += v[j];
            }
            ans = min(ans, max(sum1, sum2));
        }
        cout << ans << endl;
    }
    return 0;
}
