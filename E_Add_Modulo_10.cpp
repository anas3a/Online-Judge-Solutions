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
    vi v;
    while (t--)
    {
        ll n;
        cin >> n;
        // vll v(n);
        // for (auto &i : v)
        //     cin >> i;
        for (int i = 1; i <= 1e9; i++)
        {
            if (n > 1e9)
                break;
            v.pb(n);
            n += n % 10;
        }
        cout << endl;
    }
    cout << sz(v) << endl;
    return 0;
}