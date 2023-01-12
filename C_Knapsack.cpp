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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, w;
        cin >> n >> w;
        vpl v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].ff;
            v[i].ss = i + 1;
        }
        ll x = w / 2;
        if (w & 1)
            x++;
        sort(rall(v));
        ll sum = 0;
        vll ans;
        bool f = false;
        for (int i = 0; i < n; i++)
        {
            if (v[i].ff > w)
                continue;
            else
            {
                if (w - sum < v[i].ff)
                    continue;
                else
                {
                    sum += v[i].ff;
                    ans.pb(v[i].ss);
                }
                if (sum >= x)
                {
                    f = true;
                    cout << sz(ans) << endl;
                    sort(all(ans));
                    for (auto &i : ans)
                        cout << i << " ";
                    cout << endl;
                    break;
                }
            }
        }
        if (!f)
            cout << -1 << endl;
    }
    return 0;
}
