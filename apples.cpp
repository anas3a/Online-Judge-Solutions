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
        string s;
        cin >> n >> s;
        vi v = {2, 3, 4};
        ll ans = INT_MAX;
        do
        {
            ll cnta = 0, cntc = 0;
            for (int i = 0, j = 0, k = 1; i < sz(s); i++, k++)
            {
                if (v[j] == 2 && s[i] == '*')
                    cnta++;
                else if (v[j] == 4 && s[i] == '*')
                    cntc++;
                if (k == v[j])
                {
                    j = (j + 1) % 3;
                    k = 0;
                }
            }
            ans = min(ans, abs(cnta - cntc));
        } while (next_permutation(all(v)));
        cout << ans << endl;
    }
    return 0;
}