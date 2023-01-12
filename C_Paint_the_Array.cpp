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
        ll og = 0, eg = 0;
        for (int i = 0; i < n; i += 2)
            og = __gcd(og, v[i]);
        for (int i = 1; i < n; i += 2)
            eg = __gcd(eg, v[i]);
        if (og == eg || (og == 1 && eg == 1))
            cout << 0 << endl;
        else
        {
            ll val = -1;
            if (og != 1)
            {
                bool flag = true;
                for (int i = 1; i < n; i += 2)
                {
                    if (v[i] % og == 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    val = og;
            }
            if (eg != 1)
            {
                bool flag = true;;
                for (int i = 0; i < n; i += 2)
                {
                    if (v[i] % eg == 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    val = eg;
                }
            }
            if (val == -1)
                cout << 0 << endl;
            else
                cout << val << endl;
        }
    }
    return 0;
}