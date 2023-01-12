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

    ll v1, v2, t, d, x, sum = 0;
    cin >> v1 >> v2 >> t >> d;
    sum = x = v1;
    for (int i = 2; i <= t; i++)
    {
        if (x + d <= v2)
            x += d;
        else
        {
            if (x - ((t - i + 1) * d) < v2)
            {
                if (x - ((t - i) * d) < v2)
                    x += min(d, abs(x - (((t - i) * d) + v2)));
                else
                    x -= min(d, abs(x - (((t - i) * d) + v2)));
            }
            else
                x -= min(d, x - v2);
        }
        sum += x;
    }
    cout << sum << endl;
    return 0;
}
