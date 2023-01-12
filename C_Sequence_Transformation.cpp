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

    ll n;
    cin >> n;
    vll v((n + 1) / 2, 1);
    if (n == 3)
        v.pb(3);
    else
    {
        ll x = 2;
        while (x <= n)
        {
            ll z = (n / x) - (n / (x * 2));
            for (int i = 0; i < z; i++)
                v.pb(x);
            x *= 2;
        }
        if (n > 1 && v[n - 1] != v[n - 2] && (n / v[n - 2]) * v[n - 2] > v[n - 1])
            v[n - 1] = (n / v[n - 2]) * v[n - 2];
    }
    for (auto &i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
