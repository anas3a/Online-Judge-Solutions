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
        int n;
        cin >> n;
        vll v(n);
        for (auto &i : v)
            cin >> i;
        ll mn = 0, mx = 0, ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            mn = max(v[i], v[i + 1]);
            mx = min(v[i], v[i + 1]);
            ans = max(ans, mn * mx);
        }
        cout << ans << endl;
    }
    return 0;
}
