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
    ll z = n * (n + 1) / 2;
    if (z & 1)
        cout << "NO" << endl;
    else
    {
        vll a, b;
        int j = n;
        if (j & 1)
        {
            j--;
            a.pb(n);
        }
        for (int i = 1; i < j; i++, j--)
        {
            if ((n & 1) && j - i == 1)
            {
                if (sz(a) > sz(b))
                {
                    b.pb(i);
                    b.pb(j);
                }
                else
                {
                    a.pb(i);
                    b.pb(j);
                }
            }
            else if (i & 1)
            {
                a.pb(i);
                a.pb(j);
            }
            else
            {
                b.pb(i);
                b.pb(j);
            }
        }
        cout << "YES" << endl;
        sort(all(a));
        sort(all(b));
        cout << sz(a) << endl;
        for (auto &i : a)
            cout << i << " ";
        cout << endl;
        cout << sz(b) << endl;
        for (auto &i : b)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
