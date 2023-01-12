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
        vll v(n);
        for (auto &i : v)
            cin >> i;
        bool f = true;
        for (int i = 1; i < n - 1; i++)
        {
            ll x = 1e8, y = 1e8;
            for (int j = 0; j < i; j++)
                x = min(x, v[j]);
            for (int j = i + 1; j < n; j++)
                y = min(y, v[j]);
            if (x + y < v[i])
            {
                f = false;
                break;
            }
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
