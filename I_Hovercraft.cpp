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

    while (true)
    {
        ll l, w;
        cin >> l >> w;
        if (l + w == 0)
            break;
        double mn = LLONG_MAX;
        ll val;
        for (int i = l / 2; i <= l; i++)
        {
            ll c = l - i;
            if (i < c)
                continue;
            double b = sqrt((i * i) - (c * c));
            double temp_ans = (2 * i) + (w - b);
            if (temp_ans < mn)
            {
                mn = temp_ans;
                val = i;
            }
        }
        double vx = 0.0001, mid = val;
        for (int i = 0; i < 10000; i++)
        {
            mid -= vx;
            double c = l - mid;
            if (mid < c)
                continue;
            double b = sqrt((mid * mid) - (c * c));
            double temp_ans = (2 * mid) + (w - b);
            if (temp_ans < mn)
            {
                mn = temp_ans;
            }
        }
        vx = 0.0001, mid = val;
        for (int i = 0; i < 10000; i++)
        {
            mid += vx;
            double c = l - mid;
            if (mid < c)
                continue;
            double b = sqrt((mid * mid) - (c * c));
            double temp_ans = (2 * mid) + (w - b);
            if (temp_ans < mn)
            {
                mn = temp_ans;
            }
        }
        cout << fixed << setprecision(4) << mn << '\n';
    }
    return 0;
}