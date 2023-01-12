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
        ll a, b, ans = 0, x = 0, cnt = 0;
        string s;
        cin >> a >> b >> s;
        bool f = true;
        for (int i = 0; i < sz(s); i++)
        {
            if (s[i] == '1')
            {
                if (f)
                {
                    ans += a;
                    f = false;
                    cnt = 0;
                }
                else
                {
                    ans += min(a, cnt * b);
                    cnt = 0;
                }
            }
            else
            {
                cnt++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
