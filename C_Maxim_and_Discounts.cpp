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
    cin >> m;
    vll vm(m);
    for (auto &i : vm)
        cin >> i;
    cin >> n;
    vll vn(n);
    for (auto &i : vn)
        cin >> i;
    sort(rall(vn));
    ll x = *min_element(all(vm));
    ll ans = 0;
    for (int i = 0, j = 1; i < n; i++, j++)
    {
        if (j <= x)
            ans += vn[i];
        else
        {
            j = 0;
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}
