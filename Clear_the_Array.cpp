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
        ll n, k, x;
        cin >> n >> k >> x;
        vpl v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].ff;
            v[i].ss = i;
        }
        sort(rall(v));
        ll ans = 0;
        set<int> s;
        for (int i = 0; i < n - 1; i += 2)
        {
            if (k == 0 || v[i].ff + v[i + 1].ff <= x)
                break;
            ans += x;
            k--;
            s.insert(i);
            s.insert(i + 1);
        }
        for (int i = 0; i < n; i++)
        {
            if (s.count(i) == 0)
                ans += v[i].ff;
        }
        cout << ans << endl;
    }
    return 0;
}
