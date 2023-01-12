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
        ll n, l, r;
        cin >> n >> l >> r;
        vll v(n);
        ll sum = 0;
        for (auto &i : v)
            cin >> i, sum += i;
        ll z = (r - l + 1) / n;
        ll ans = sum * z;
        l += z * n;
        for (int i = l; i <= r; i++)
        {
            ll x = i % n;
            if (x == 0)
                x = n;
            ans += v[x - 1];
        }
        cout << ans << endl;
    }
    return 0;
}
