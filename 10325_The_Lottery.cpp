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

    ll n, m;
    while (cin >> n >> m)
    {
        vll v(m);
        for (auto &i : v)
            cin >> i;
        ll cnt = 0;
        for (int i = 0; i < m; i++)
        {
            cnt += n / v[i];
        }
        for (ll i = 0; i < (1 << m); i++)
        {
            ll lc = 0, cntx = 0;
            for (ll j = 0; j < m; j++)
            {
                if ((i & (1 << j)) != 0)
                {
                    if (lc == 0)
                        lc = v[j];
                    else
                    {
                        lc = (lc / __gcd(lc, v[j])) * v[j];
                    }
                    cntx++;
                }
            }
            if (cntx >= 2)
            {
                if (cntx & 1)
                    cnt += n / lc;
                else
                    cnt -= n / lc;
            }
        }
        cout << n - cnt << endl;
    }
    return 0;
}
