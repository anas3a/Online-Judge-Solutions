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

    int n, cs = 0;
    cin >> n;
    while (n--)
    {
        ll k, x = 0;
        cin >> k;
        vi v1(k), v2(k);
        vpl v;
        for (auto &i : v1)
            cin >> i;
        for (auto &i : v2)
            cin >> i;
        ll y = 0;
        ll z = 0;
        for (int i = 0; i < k; i++)
        {
            if (v2[i] == -1)
            {
                x++;
                continue;
            }
            v.pb(mp(v2[i] - 30, v1[i]));
        }
        sort(all(v));
        for (int i = 0; i < sz(v); i++)
        {
            if (z + v[i].ss > v[i].ff)
                continue;
            z += v[i].ss;
            y++;
        }
        cout << "Case " << ++cs << ": " << k - y - x << endl;
    }
    return 0;
}
