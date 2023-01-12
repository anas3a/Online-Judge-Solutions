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
        ll n, m;
        cin >> n >> m;
        vector<vll> v(m, vll(3));
        for (int i = 0; i < m; i++)
        {
            cin >> v[i][1] >> v[i][0];
            v[i][2] = i + 1;
        }
        sort(all(v));
        vpl ans1;
        ll sum = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            sum += v[i][0];
            ans1.pb({v[i][1], v[i][2]});
        }
        cout << sum << endl;
        sort(all(ans1));
        for (int i = 0, j = 2 * n - 1; i < n; i++, j--)
        {
            cout << ans1[i].ss << " " << ans1[j].ss << endl;
        }
        cout << endl;
    }
    return 0;
}