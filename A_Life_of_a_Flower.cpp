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
        ll n, prev = -1;
        cin >> n;
        ll ans = 1;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (ans != -1 && x && prev != 1)
                ans++;
            else if (ans != -1 && x == 0 && x == prev)
                ans = -1;
            else if (ans != -1 && x == 1 && prev == 1)
                ans += 5;
            prev = x;
        }
        cout << ans << endl;
    }
    return 0;
}