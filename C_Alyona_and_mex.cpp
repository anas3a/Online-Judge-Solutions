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

    ll n, m;
    cin >> n >> m;
    ll ans = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        ll l, r;
        cin >> l >> r;
        ans = min(ans, r - l + 1);
    }
    vll v(n);
    for (int i = 0, x = 0; i < n; i++)
    {
        v[i] = x++;
        if (x == ans)
            x = 0;
    }
    cout << ans << endl;
    for (auto &i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
