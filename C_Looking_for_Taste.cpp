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

    freopen("looking.in", "r", stdin);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll mx = 0, mxx = 0;
        vll v(n);
        for (auto &i : v)
            cin >> i;
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((mx | v[j]) > mxx)
                    mxx = (mx | v[j]);
            }
            mx = mxx;
        }
        cout << mx << endl;
    }
    return 0;
}