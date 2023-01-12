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
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;
    vvl v(n);
    for (int i = 0; i < n; i++)
    {
        ll l;
        cin >> l;
        for (int j = 0; j < l; j++)
        {
            ll x;
            cin >> x;
            v[i].pb(x);
        }
    }
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << v[a][b] << nl;
    }
    return 0;
}