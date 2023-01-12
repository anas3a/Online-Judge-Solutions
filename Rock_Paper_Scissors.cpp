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
        vi vr, vp, vs;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'R')
                vr.pb(i);
            else if (s[i] == 'P')
                vp.pb(i);
            else
                vs.pb(i);
        }
        string ans(n, 'X');
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'R')
            {
                ll ind = lower_bound(all(vp), i) - vp.begin();
                if (ind == sz(vp))
                    ans[i] = s[i];
                else
                    ans[i] = ans[vp[ind]];
            }
            else if (s[i] == 'P')
            {
                ll ind = lower_bound(all(vs), i) - vs.begin();
                if (ind == sz(vs))
                    ans[i] = s[i];
                else
                    ans[i] = ans[vs[ind]];
            }
            else
            {
                ll ind = lower_bound(all(vr), i) - vr.begin();
                if (ind == sz(vr))
                    ans[i] = s[i];
                else
                    ans[i] = ans[vr[ind]];
            }
        }
        cout << ans << endl;
    }
    return 0;
}