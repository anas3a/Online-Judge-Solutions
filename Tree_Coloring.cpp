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

ll md = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, c;
    cin >> n >> c;
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
    }
    bool flag = false;
    ll ans = 1;
    for (int i = 0; i < n - 1; i++)
    {
        ans = (ans * c) % md;
        if (i < 2)
            c--;
        if (c == 0 && i != n - 1)
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << 0 << endl;
    else
        cout << ans << endl;
    return 0;
}