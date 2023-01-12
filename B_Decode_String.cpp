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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        string s, ans;
        cin >> n >> s;
        reverse(all(s));
        for (int i = 0; i < n; i++)
        {
            ll x = s[i] - '0';
            if (x)
            {
                ans += 'a' + (x - 1);
            }
            else
            {
                ll z = s[i + 2] - '0';
                z *= 10;
                z += s[i + 1] - '0';
                ans += 'a' + (z - 1);
                i += 2;
            }
        }
        reverse(all(ans));
        cout << ans << endl;
    }
    return 0;
}