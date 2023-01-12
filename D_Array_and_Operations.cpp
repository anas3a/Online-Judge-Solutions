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
        ll n, k;
        cin >> n >> k;
        vll v(n);
        for (auto &i : v)
            cin >> i;
        sort(all(v));
        ll ans = 0;
        for (int i = 0; i < n - k * 2; i++)
            ans += v[i];
        map<ll, ll> mp;
        for (int j = n - k * 2; j < n; j++)
            mp[v[j]]++;
        ll mx = 0;
        for (auto &i : mp)
            mx = max(mx, i.ss);
        if (mx > k)
        {
            mx -= k * 2 - mx;
            ans += mx / 2;
        }
        cout << ans << endl;
    }
    return 0;
}