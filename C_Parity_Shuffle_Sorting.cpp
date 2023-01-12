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
        ll n;
        cin >> n;
        vll v(n);
        for (auto &i : v)
            cin >> i;
        ll x = v[0] + v[n - 1];
        if (x & 1)
            v[n - 1] = v[0];
        else
            v[0] = v[n - 1];
        vll odd, eve;
        ll z = v[n - 1] % 2;
        cout << n - 1 << nl;
        if (n == 1)
            continue;
        cout << 1 << " " << n << nl;
        for (int i = 1; i < n - 1; i++)
        {
            if (v[i] % 2 == z)
                cout << i + 1 << " " << n << nl;
            else
                cout << 1 << " " << i + 1 << nl;
        }
    }
    return 0;
}