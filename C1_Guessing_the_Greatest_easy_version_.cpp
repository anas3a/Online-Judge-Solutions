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

ll ask(ll l, ll r)
{
    cout << "? " << l << " " << r << endl;
    ll x;
    cin >> x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll l = 1, r = n;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        ll z = ask(l, r);
        if (z <= m)
        {
            if (ask(l, m) == z)
                r = m;
            else
                l = m;
        }
        else
        {
            if (ask(m, r) == z)
                l = m;
            else
                r = m;
        }
    }
    if (ask(l, r) == l)
        cout << "! " << r << endl;
    else
        cout << "! " << l << endl;
    return 0;
}