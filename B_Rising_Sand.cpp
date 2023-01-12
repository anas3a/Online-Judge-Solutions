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
        ll n, k;
        cin >> n >> k;
        vll v(n);
        for (auto &i : v)
            cin >> i;
        if (k == 1)
        {
            cout << (n - 1) / 2 << endl;
        }
        else
        {
            ll ans = 0;
            for (int i = 1; i < n - 1; i++)
            {
                if (v[i] > v[i - 1] + v[i + 1])
                    ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}