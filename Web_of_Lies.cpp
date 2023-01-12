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

    ll n, m;
    cin >> n >> m;
    vll v(n + 1, 0);
    ll ans = n;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if (v[a] == 0)
            ans--;
        v[a]++;
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        if (x == 3)
            cout << ans << endl;
        else
        {
            ll a, b;
            cin >> a >> b;
            if (a > b)
                swap(a, b);
            if (x == 1)
            {
                if (v[a] == 0)
                    ans--;
                v[a]++;
            }
            else
            {
                if (v[a] > 0)
                    v[a]--;
                if (v[a] == 0)
                    ans++;
            }
        }
    }
    return 0;
}
