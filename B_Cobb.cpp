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

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vll v(n);
        ll mn = INT_MAX, in1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] <= mn)
            {
                mn = v[i];
                in1 = i + 1;
            }
        }
        ll a = INT_MAX, in2;
        for (int i = 0; i < n; i++)
        {
            if (i == in1 - 1)
                continue;
            if ((mn | v[i]) <= a)
            {
                a = mn | v[i];
                in2 = i + 1;
            }
        }
        ll ans = (in1 * in2) - (k * a);

        ll in3, cx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (i + 1 - v[i] >= cx)
            {
                cx = i + 1 - v[i];
                in3 = i + 1;
            }
        }
        ll b = INT_MAX, in4, mt = v[in3 - 1];
        for (int i = 0; i < n; i++)
        {
            if (i == in3 - 1)
                continue;
            if ((mt | v[i]) <= b)
            {
                b = mt | v[i];
                in4 = i + 1;
            }
        }
        ans = max(ans, (in3 * in4) - (k * b));
        cout << ans << endl;
    }
    return 0;
}
