#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
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
        ll n;
        cin >> n;
        ll x = 4 * n;
        vll v;
        for (int i = 0; i < n; i++)
        {
            cout << x << " ";
            v.pb(x);
            while (true)
            {
                x--;
                bool f = true;
                for (int i = 0; i < sz(v); i++)
                {
                    if (x % v[i] == 0 || __gcd(x, v[i]) == 1)
                    {
                        f = false;
                        break;
                    }
                }
                if (f)
                    break;
            }
        }
        cout << endl;
    }
    return 0;
}
