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
        ll n;
        cin >> n;
        map<ll, ll> s;
        bool f = false;
        ll z;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (x == 1)
                f = true;
            if (x == 0 || x == 1)
                continue;
            z = x;
            s[x]++;
        }
        if (sz(s) == 0)
            cout << 1 << endl;
        else if (sz(s) > 1)
            cout << 0 << endl;
        else
        {
            if (s[z] == 1)
                cout << 1 << endl;
            else if (z == -1 && f)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}
