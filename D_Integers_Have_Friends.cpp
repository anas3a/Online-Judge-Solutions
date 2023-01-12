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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll v(n);
        for (auto &i : v)
            cin >> i;
        ll gc = 0, ans = 1;
        vll vx(n + 1);
        for (int i = 1, j = 1; i <= n; i++)
        {
            vx[i] = __gcd(v[i - 1], v[i]);
            if (vx[i] == 1)
                j = i;
            else
                while (max(vx[j], vx[i]) % min(vx[j], vx[i]) != 0)
                    j++;
            ans = max(ans, i - j + 1ll);
        }
        cout << ans << endl;
    }
    return 0;
}
