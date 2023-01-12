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

    ll t, cs = 0;
    cin >> t;
    while (t--)
    {
        ll p, l;
        cin >> p >> l;
        p -= l;
        vll div;
        for (ll i = 1; i * i <= p; i++)
        {
            if (p % i == 0)
            {
                div.pb(i);
                if (i != p / i)
                    div.pb(p / i);
            }
        }
        sort(all(div));
        bool flag = true;
        cout << "Case " << ++cs << ":";
        for (auto &i : div)
        {
            if (i > l)
                cout << " " << i, flag = false;
        }
        if (flag)
            cout << " impossible";
        cout << endl;
    }
    return 0;
}