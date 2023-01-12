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
        ll ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ll cnt = 1;
            ll x = v[i];
            for (int j = i + 1; j < n; j++)
            {
                if (v[j] - 1 == x)
                {
                    cnt++;
                    x = v[j];
                }
            }
            ans = min(ans, n - cnt);
        }
        for (int i = 0; i < n; i++)
        {
            ll cnt = 1;
            ll x = v[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (v[j] - 1 == x)
                {
                    cnt++;
                    x = v[j];
                }
            }
            ans = min(ans, n - cnt);
        }
        for (int i = 0; i < n; i++)
        {
            ll cnt = 1;
            ll x = v[i];
            for (int j = i + 1; j < n; j++)
            {
                if (v[j] + 1 == x)
                {
                    cnt++;
                    x = v[j];
                }
            }
            ans = min(ans, n - cnt);
        }
        for (int i = 0; i < n; i++)
        {
            ll cnt = 1;
            ll x = v[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (v[j] + 1 == x)
                {
                    cnt++;
                    x = v[j];
                }
            }
            ans = min(ans, n - cnt);
        }
        map<ll, ll> mp;
        for (int i = 0; i < n; i++)
        {
            mp[v[i]]++;
        }
        ll mx = 0;
        ll val;
        for (auto &i : mp)
        {
            if (i.ss > mx)
            {
                mx = i.ss;
                val = i.ff;
            }
        }
        ans = min(ans, n - mx);
        if (n <= 2)
            ans = 0;
        cout << ans << endl;
    }
    return 0;
}