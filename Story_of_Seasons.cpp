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
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

ll d, n, x;
vvl v;
// ll dp[50000];
// int turnOn(ll x, ll pos)
// {
//     return x | (1 << pos);
// }

// bool isOn(ll x, ll pos)
// {
//     return (bool)(x & (1 << pos));
// }

// ll f(ll mask, ll dx)
// {
//     if (mask == (1 << n) - 1)
//         return 0;
//     if (dp[mask] != -1)
//         return dp[mask];
//     ll ans = 0;
//     for (int j = 0; j < n; j++)
//     {
//         if (isOn(mask, j) == 0)
//         {
//             ll tmp = 0;
//             if (v[j][1] < dx)
//                 tmp = v[j][2];
//             ans = max(ans, f(turnOn(mask, j), dx - 1) + tmp);
//         }
//     }
//     return dp[mask] = ans;
// }
bool comp(vll a, vll b)
{
    if (a[1] == b[1] && a[2] == b[2])
        return a[0] > b[0];
    if (a[2] == b[2])
        return a[1] > b[1];
    return a[2] > b[2];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        cin >> d >> n >> x;
        v.clear();
        v.resize(n, vll(3));
        // memset(dp, -1, sizeof(dp));
        for (auto &i : v)
            for (auto &j : i)
                cin >> j;
        // cout << "Case #" << ++cs << ": " << f(0, d) << nl;

        ll ans = 0;
        set<int> st;
        vll vx(d, x);
        for (int i = 2; i < d; i++)
            st.insert(i);
        sort(all(v), comp);

        for (int i = 0; i < n; i++)
        {
            ll z = v[i][0];
            while (true)
            {
                auto it = st.lower_bound(v[i][1]);
                if (it == st.end())
                    break;
                int x = *it;
                if (vx[x] >= z)
                {
                    vx[x] -= z;
                    if (vx[x] == 0)
                        st.erase(x);
                    z = 0;
                    break;
                }
                else
                {
                    z -= vx[x];
                    vx[x] = 0;
                    st.erase(x);
                }
                if (!z)
                    break;
            }
            ans += v[i][2] * (v[i][0] - z);
        }
        cout << "Case #" << ++cs << ": " << ans << nl;
    }
    return 0;
}