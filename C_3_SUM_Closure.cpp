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
        vll v(n);
        for (auto &i : v)
            cin >> i;
        sort(all(v));
        if (v[0] == 0 && v[0] == v[n - 1])
            cout << "YES" << endl;
        else
        {
            vll vx;
            for (auto &i : v)
            {
                if (i)
                    vx.pb(i);
            }
            bool flag = true;
            ll nx = sz(vx);
            ll x = abs(vx[0]), y = vx[nx - 1];
            ll cntx = 0, cnty = 0, cntz = 0;
            for (int i = 0; i < nx; i++)
            {
                if (vx[i] != x &&  vx[i] != x * -1)
                {
                    cntz++;
                }
                
            }
            for (int i = 0; i < nx; i++)
            {
                if (vx[i] != x && vx[i] != y)
                {
                    flag = false;
                    break;
                }
                if (vx[i] == x)
                    cntx++;
                else
                    cnty++;
            }
            if (abs(cntx - cnty) > 1 || cntx > 2 || cnty > 2)
            {
                flag = false;
            }
            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}