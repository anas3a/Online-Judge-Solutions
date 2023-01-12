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

ll cntinv(vll v)
{
    ll cntx = 0, ans = 0;
    for (auto &i : v)
    {
        cntx += i;
        if (!i)
            ans += cntx;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll v(n);
        for (auto &i : v)
            cin >> i;
        ll ans = 0;
        vll v1 = v;
        for (int i = 0; i < n; i++)
        {
            if (v1[i] == 1)
            {
                v1[i] = 0;
                break;
            }
        }
        ans = cntinv(v1);
        vll v2 = v;
        for (int i = 0; i < n; i++)
        {
            if (v2[i] == 0)
            {
                v2[i] = 1;
                break;
            }
        }
        ans = max(cntinv(v2), ans);
        vll v3 = v;
        for (int i = n - 1; i >= 0; i--)
        {
            if (v3[i] == 0)
            {
                v3[i] = 1;
                break;
            }
        }
        ans = max(cntinv(v3), ans);
        vll v4 = v;
        for (int i = n - 1; i >= 0; i--)
        {
            if (v4[i] == 1)
            {
                v4[i] = 0;
                break;
            }
        }
        ans = max(cntinv(v4), ans);
        cout << ans << endl;
    }
    return 0;
}