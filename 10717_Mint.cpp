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

    while (true)
    {
        ll n, t;
        cin >> n >> t;
        if (n + t == 0)
            break;
        vll v(n), vx(t);
        vpl ans(t, {0, LLONG_MAX});
        for (auto &i : v)
            cin >> i;
        for (auto &i : vx)
            cin >> i;
        for (int i = 0; i < n - 3; i++)
        {
            ll g1 = v[i];
            for (int j = i + 1; j < n - 2; j++)
            {
                ll g2 = g1 / __gcd(v[j], g1) * v[j];
                for (int k = j + 1; k < n - 1; k++)
                {
                    ll g3 = g2 / __gcd(v[k], g2) * v[k];
                    for (int l = k + 1; l < n; l++)
                    {
                        ll g4 = g3 / __gcd(v[l], g3) * v[l];
                        for (int m = 0; m < t; m++)
                        {
                            ll a1 = vx[m] / g4;
                            if (a1 > 0 && vx[m] - (g4 * a1) < vx[m] - ans[m].ff)
                            {
                                ans[m].ff = g4 * a1;
                            }
                            if (g4 * a1 == vx[m])
                                ans[m].ss = g4 * a1;
                            else if (g4 * (a1 + 1) - vx[m] < ans[m].ss - vx[m])
                                ans[m].ss = g4 * (a1 + 1);
                        }
                    }
                }
            }
        }
        for (auto &i : ans)
            cout << i.ff << " " << i.ss << endl;
    }
    return 0;
}
