#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
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

    ll n, p, ans = 0;
    string s;
    cin >> n >> p >> s;
    vi v(n, 0);
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            char c = max(s[i], s[j]), d = min(s[i], s[j]);
            v[i] = v[j] = min(c - d, 'z' - c + d + 1 - 'a');
        }
    }
    p--;
    ll x = n / 2;
    for (int i = 0; i < x; i++)
        ans += v[i];
    if (p < x)
    {
        ll a = 0, b = 0;
        for (int i = 0; i < p; i++)
        {
            if (v[i] != 0)
            {
                a = p - i;
                break;
            }
        }
        for (int i = x - 1; i > p; i--)
        {
            if (v[i] != 0)
            {
                b = i - p;
                break;
            }
        }
        ans += min(a + (b * 2), b + (a * 2));
    }
    else
    {
        if (n & 1)
            x++;
        ll a = 0, b = 0;
        for (int i = x; i < p; i++)
        {
            if (v[i] != 0)
            {
                a = p - i;
                break;
            }
        }
        for (int i = n - 1; i > p; i--)
        {
            if (v[i] != 0)
            {
                b = i - p;
                break;
            }
        }
        ans += min(a + (b * 2), b + (a * 2));
    }
    cout << ans << endl;
    return 0;
}
