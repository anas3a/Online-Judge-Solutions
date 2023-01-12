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
        cin >> n;
        vll v(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        ll sum = 0, ans = LLONG_MAX;
        for (int i = 1; i <= n; i++)
        {
            sum += v[i];
            ll cnt = 0, mx = 0;
            ll sumx = 0, cx = 1;
            for (int j = 1; j <= n; j++, cx++)
            {
                sumx += v[j];
                if (sumx == sum)
                {

                    sumx = 0;
                    mx = max(mx, cx);
                    cx = 0;
                }
            }
            if (sumx)
                continue;
            mx = max(mx, cx);
            ans = min(ans, mx);
        }
        cout << ans << nl;
    }
    return 0;
}