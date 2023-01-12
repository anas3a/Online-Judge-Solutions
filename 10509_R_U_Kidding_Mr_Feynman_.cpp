#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
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

    double x;
    while (cin >> x)
    {
        if (x == 0.0)
            break;
        double low = 0, high = x, mid = (high + low) / 2.0;
        for (int i = 0; i < 99; i++)
        {
            if (mid * mid * mid > x)
                high = mid;
            else
                low = mid;
            mid = (high + low) / 2.0;
        }
        cout << fixed << setprecision(4) << mid << endl;
    }
    return 0;
}
