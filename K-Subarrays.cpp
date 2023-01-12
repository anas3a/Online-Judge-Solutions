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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, gc = 0;
        cin >> n >> k;
        vll v(n);
        for (auto &i : v)
            cin >> i, gc = __gcd(i, gc);
        ll cnt = 0, gcx = 0;
        for (int i = 0; i < n; i++)
        {
            gcx = __gcd(gcx, v[i]);
            if (gcx == gc)
            {
                cnt++;
                gcx = 0;
            }
        }
        if (cnt >= k)
            cout << "YES" << nl;
        else
            cout << "NO" << nl;
    }
    return 0;
}