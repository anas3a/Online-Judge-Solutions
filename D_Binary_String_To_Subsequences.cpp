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
        string s;
        cin >> s;
        vll ans(n), v1, v0;
        for (int i = 0; i < n; i++)
        {
            ll x = sz(v1) + sz(v0) + 1;
            if (s[i] == '0')
            {
                if (v1.empty())
                    v0.pb(x);
                else
                {
                    v0.pb(v1.back());
                    v1.pop_back();
                    x = v0.back();
                }
            }
            else
            {
                if (v0.empty())
                    v1.pb(x);
                else
                {
                    v1.pb(v0.back());
                    v0.pop_back();
                    x = v1.back();
                }
            }
            ans[i] = x;
        }
        cout << sz(v0) + sz(v1) << endl;
        for (auto &i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
