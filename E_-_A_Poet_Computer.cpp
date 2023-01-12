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

    ll t, cs = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            reverse(all(s));
            transform(all(s), s.begin(), ::tolower);
            v[i] = s;
        }
        vll vx;
        for (int i = 1; i < n; i++)
        {
            int j = 0;
            while (j < sz(v[i]) && j < sz(v[i - 1]))
            {
                if (v[i][j] != v[i - 1][j])
                    break;
                j++;
            }
            vx.pb(j);
        }
        ll mx = 0, ind;
        for (int i = 0; i < n - 1; i++)
        {
            if (min(vx[i], vx[i + 1]) > mx)
            {
                mx = max(mx, min(vx[i], vx[i + 1]));
                ind = i;
            }
        }
        cout << "Case " << ++cs << ": " << endl;
        cout << mx << " ";
        ll cnt = 0, cntx = 0;
        ll x = vx[0];
        vx.insert(vx.begin(), x);
        string sx;
        for (int i = 0; i < mx; i++)
        {
            sx += v[ind][i];
        }
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            for (int k = 0; k < sz(v[i]) && k < sz(v[ind]); k++)
            {
                if (v[i][k] != v[ind][k])
                    break;
                j++;
            }
            if (j >= mx)
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}