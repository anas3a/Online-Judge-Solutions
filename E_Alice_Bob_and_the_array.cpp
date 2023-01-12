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

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vll v(n);
        ll sum = 0, mx = INT_MIN;
        for (auto &i : v)
        {
            cin >> i;
            if (i > 0)
                sum += i;
            mx = max(mx, i);
        }
        if (mx <= 0)
        {
            cout << "Case " << ++cs << ": " << mx << " " << 0 << "\n";
            continue;
        }
    }
    return 0;
}
