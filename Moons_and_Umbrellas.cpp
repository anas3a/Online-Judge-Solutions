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

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        char c = 'X';
        string s;
        ll x, y;
        cin >> x >> y >> s;
        ll ans = 0;
        for (int i = 0; i < sz(s) - 1; i++)
        {
            if (s[i] != '?')
            {
                if (s[i + 1] != '?' && s[i + 1] != s[i])
                {
                    if (s[i] == 'C')
                        ans += x;
                    else
                        ans += y;
                }
            }
        }
        for (int i = 0; i < sz(s) - 1; i++)
        {
            if (s[i] != '?')
                c = s[i];
            if (s[i] == '?' && s[i + 1] != '?')
            {
                if (s[i + 1] == c || c == 'X')
                    continue;
                if (c == 'C')
                    ans += x;
                else
                    ans += y;
            }
        }
        cout << "Case #" << ++cs << ": " << ans << endl;
    }
    return 0;
}
