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
        string s;
        cin >> n >> k >> s;
        sort(all(s));
        if (s[k - 1] != s[0])
            cout << s[k - 1] << endl;
        else
        {
            ll cnt = 0;
            string ans;
            for (int i = 0; i < n - 1; i++)
            {
                if (s[i] != s[i + 1])
                    cnt++;
            }
            if (cnt > 1)
            {
                for (int i = k - 1; i < n; i++)
                    ans += s[i];
            }
            else if (cnt == 0)
            {
                ll z = n / k;
                if (n % k)
                    z++;
                string sx(z, s.front());
                ans = sx;
            }
            else
            {
                if (s[k - 1] == s[k])
                {
                    for (int i = k - 1; i < n; i++)
                        ans += s[i];
                }
                else
                {
                    ans += s[k - 1];
                    ll z = (n - k) / k;
                    if ((n - k) % k)
                        z++;
                    for (int i = 0; i < z; i++)
                        ans += s[n - 1];
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
