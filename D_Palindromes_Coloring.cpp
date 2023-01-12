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
        string s;
        cin >> s;
        vll v(26, 0);
        for (int i = 0; i < n; i++)
        {
            v[s[i] - 'a']++;
        }
        ll cnt = 0;
        for (int i = 0; i < 26; i++)
            cnt += v[i] / 2;
        ll ans = cnt / k;
        ans *= 2;
        bool flag = false;
        ll cx = 0;
        for (int i = 0; i < 26; i++)
        {
            if (v[i] & 1)
            {
                cx++;
            }
        }
        if (n - (ans * k) >= k)
            ans++;
        ans = max(ans, 1ll);
        cout << ans << endl;
    }
    return 0;
}