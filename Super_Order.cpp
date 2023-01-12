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

pair<int, int> v[20][20];
int n;
ll dp[10004][20];
int turnOn(int x, int pos)
{
    return (x | (1 << pos));
}

bool isOn(int x, int pos)
{
    return (bool)(x & (1 << pos));
}

ll f(ll bits, ll ii)
{
    if (bits == (1 << n) - 1)
        return 0;
    if (dp[bits][ii] != -1)
        return dp[bits][ii];
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isOn(bits, i) == 0)
        {
            ll result = v[ii][i].ff;
            if (v[ii][i].ss)
                result += f(turnOn(bits, i), ii);
            else
                result += f(turnOn(bits, ii), i);
            ans = max(ans, result);
        }
    }
    return dp[bits][ii] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, cs = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin.ignore();
        memset(dp, -1, sizeof(dp));
        cout << "Case " << ++cs << ": ";
        for (int ii = 1, j = 1; ii <= n; ii++)
        {
            string s;
            getline(cin, s);
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    ll num = 0;
                    while (s[i] >= '0' && s[i] <= '9')
                    {
                        num *= 10;
                        num += s[i] - '0';
                        i++;
                    }
                    i--;
                    v[ii][j].first = num;
                }
                if (s[i] == 'F')
                {
                    v[ii][j].second = 0;
                    j++;
                }
                if (s[i] == 'T')
                {
                    v[ii][j].second = 1;
                    j++;
                }
            }
            j = 1;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, f(0, i));
        cout << ans << '\n';
    }
    return 0;
}